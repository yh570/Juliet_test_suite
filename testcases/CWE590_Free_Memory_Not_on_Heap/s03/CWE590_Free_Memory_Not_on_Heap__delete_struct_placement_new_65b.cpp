/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_struct_placement_new_65b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-65b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: placement_new Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_struct_placement_new_65
{


void badSink(twoIntsStruct * data)
{
    printStructLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(twoIntsStruct * data)
{
    printStructLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}


} /* close namespace */
