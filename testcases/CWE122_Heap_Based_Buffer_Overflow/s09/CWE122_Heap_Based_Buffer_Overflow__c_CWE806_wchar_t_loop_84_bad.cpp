/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84_bad::CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84_bad::~CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_84_bad()
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
        free(data);
    }
}
}
