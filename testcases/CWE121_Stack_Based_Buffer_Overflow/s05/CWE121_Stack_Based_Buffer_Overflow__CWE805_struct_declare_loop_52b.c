/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: loop
 *    BadSink : Copy twoIntsStruct array to data using a loop
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52c_badSink(twoIntsStruct * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52b_badSink(twoIntsStruct * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52c_badSink(data);
}



/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52c_goodG2BSink(twoIntsStruct * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52b_goodG2BSink(twoIntsStruct * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_loop_52c_goodG2BSink(data);
}

