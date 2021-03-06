/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_53d.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-53d.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE843_Type_Confusion__char_53d_badSink(void * data)
{
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE843_Type_Confusion__char_53d_goodG2BSink(void * data)
{
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

