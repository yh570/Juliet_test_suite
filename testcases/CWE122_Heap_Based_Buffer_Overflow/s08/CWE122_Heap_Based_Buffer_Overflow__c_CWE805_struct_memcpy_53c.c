/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy twoIntsStruct array to data using memcpy
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53d_badSink(twoIntsStruct * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53c_badSink(twoIntsStruct * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53d_badSink(data);
}



/* good function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53d_goodG2BSink(twoIntsStruct * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53c_goodG2BSink(twoIntsStruct * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_memcpy_53d_goodG2BSink(data);
}

