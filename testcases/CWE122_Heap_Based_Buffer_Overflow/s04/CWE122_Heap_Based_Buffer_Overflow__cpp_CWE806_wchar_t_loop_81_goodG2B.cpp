/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_loop_81_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_loop_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_loop_81
{

void CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_loop_81_goodG2B::action(wchar_t * data) const
{
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
        delete [] data;
    }
}

}
