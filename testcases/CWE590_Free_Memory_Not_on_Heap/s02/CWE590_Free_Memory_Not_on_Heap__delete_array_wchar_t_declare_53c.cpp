/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_wchar_t_declare_53c.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_wchar_t_declare_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_d(wchar_t * data);

void badSink_c(wchar_t * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(wchar_t * data);

void goodG2BSink_c(wchar_t * data)
{
    goodG2BSink_d(data);
}


} /* close namespace */
