/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_51b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-51b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_51b_badSink(int64_t * data)
{
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_51b_goodG2BSink(int64_t * data)
{
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

