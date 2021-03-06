/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54d.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54e_badSink(int * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54d_badSink(int * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54e_badSink(data);
}



/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54e_goodG2BSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54d_goodG2BSink(int * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_54e_goodG2BSink(data);
}

