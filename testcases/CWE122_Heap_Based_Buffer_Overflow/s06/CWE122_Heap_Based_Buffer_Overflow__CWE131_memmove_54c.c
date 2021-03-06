/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54d_badSink(int * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54c_badSink(int * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54d_badSink(data);
}



/* good function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54d_goodG2BSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54c_goodG2BSink(int * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_54d_goodG2BSink(data);
}

