/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52c_badSink(int * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52b_badSink(int * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52c_badSink(data);
}



/* good function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52c_goodG2BSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52b_goodG2BSink(int * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_52c_goodG2BSink(data);
}

