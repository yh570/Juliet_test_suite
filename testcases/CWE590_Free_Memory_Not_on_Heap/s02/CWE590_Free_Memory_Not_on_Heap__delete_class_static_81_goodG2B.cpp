/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_class_static_81_goodG2B.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__delete_class_static_81.h"

namespace CWE590_Free_Memory_Not_on_Heap__delete_class_static_81
{

void CWE590_Free_Memory_Not_on_Heap__delete_class_static_81_goodG2B::action(TwoIntsClass * data) const
{
    printIntLine(data->intOne);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}

}
