/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_struct_declare_52c.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-52c.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_struct_declare_52
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink_c(twoIntsStruct * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_c(twoIntsStruct * data)
{
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}


} /* close namespace */
