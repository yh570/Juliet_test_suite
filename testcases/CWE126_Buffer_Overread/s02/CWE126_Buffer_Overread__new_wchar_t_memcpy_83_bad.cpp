/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_wchar_t_memcpy_83_bad.cpp
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__new_wchar_t_memcpy_83.h"

namespace CWE126_Buffer_Overread__new_wchar_t_memcpy_83
{
CWE126_Buffer_Overread__new_wchar_t_memcpy_83_bad::CWE126_Buffer_Overread__new_wchar_t_memcpy_83_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a small buffer */
    data = new wchar_t[50];
    wmemset(data, L'A', 50-1); /* fill with 'A's */
    data[50-1] = L'\0'; /* null terminate */
}

CWE126_Buffer_Overread__new_wchar_t_memcpy_83_bad::~CWE126_Buffer_Overread__new_wchar_t_memcpy_83_bad()
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
        delete [] data;
    }
}
}
