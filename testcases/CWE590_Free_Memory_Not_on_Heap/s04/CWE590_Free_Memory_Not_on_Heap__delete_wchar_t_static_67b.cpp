/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_static_67b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_static_67
{

typedef struct _structType
{
    wchar_t * structFirst;
} structType;


void badSink(structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    printWcharLine(*data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    printWcharLine(*data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}


} /* close namespace */
