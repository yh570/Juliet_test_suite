/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_63b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_63b_badSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        wcscpy(dest, data);
        printWLine(data);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_63b_goodG2BSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        wcscpy(dest, data);
        printWLine(data);
        free(data);
    }
}

