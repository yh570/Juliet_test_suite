/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_memmove_83_goodG2B.cpp
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__malloc_wchar_t_memmove_83.h"

namespace CWE127_Buffer_Underread__malloc_wchar_t_memmove_83
{
CWE127_Buffer_Underread__malloc_wchar_t_memmove_83_goodG2B::CWE127_Buffer_Underread__malloc_wchar_t_memmove_83_goodG2B(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (dataBuffer == NULL) {exit(-1);}
        wmemset(dataBuffer, L'A', 100-1);
        dataBuffer[100-1] = L'\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = dataBuffer;
    }
}

CWE127_Buffer_Underread__malloc_wchar_t_memmove_83_goodG2B::~CWE127_Buffer_Underread__malloc_wchar_t_memmove_83_goodG2B()
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memmove(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}
}
