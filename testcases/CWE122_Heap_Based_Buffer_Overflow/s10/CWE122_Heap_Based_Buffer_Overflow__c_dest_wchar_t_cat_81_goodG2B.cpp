/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cat_81_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cat_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cat_81
{

void CWE122_Heap_Based_Buffer_Overflow__c_dest_wchar_t_cat_81_goodG2B::action(wchar_t * data) const
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than sizeof(data)-strlen(data) */
        wcscat(data, source);
        printWLine(data);
        free(data);
    }
}

}
