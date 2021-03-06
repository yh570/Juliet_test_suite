/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_66b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-66b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy int64_t array to data using memmove
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_66b_badSink(int64_t * dataArray[])
{
    /* copy data out of dataArray */
    int64_t * data = dataArray[2];
    {
        int64_t source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_66b_goodG2BSink(int64_t * dataArray[])
{
    int64_t * data = dataArray[2];
    {
        int64_t source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

