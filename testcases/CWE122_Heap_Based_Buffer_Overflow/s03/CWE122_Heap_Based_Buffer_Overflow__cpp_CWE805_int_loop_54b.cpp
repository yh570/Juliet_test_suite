/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_54b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-54b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy int array to data using a loop
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_c(int * data);

void badSink_b(int * data)
{
    badSink_c(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_c(int * data);

void goodG2BSink_b(int * data)
{
    goodG2BSink_c(data);
}


} /* close namespace */
