/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_wchar_t_loop_84_bad.cpp
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__new_wchar_t_loop_84.h"

namespace CWE126_Buffer_Overread__new_wchar_t_loop_84
{
CWE126_Buffer_Overread__new_wchar_t_loop_84_bad::CWE126_Buffer_Overread__new_wchar_t_loop_84_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a small buffer */
    data = new wchar_t[50];
    wmemset(data, L'A', 50-1); /* fill with 'A's */
    data[50-1] = L'\0'; /* null terminate */
}

CWE126_Buffer_Overread__new_wchar_t_loop_84_bad::~CWE126_Buffer_Overread__new_wchar_t_loop_84_bad()
{
    {
        size_t i, destLen;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        destLen = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < destLen; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
        delete [] data;
    }
}
}
