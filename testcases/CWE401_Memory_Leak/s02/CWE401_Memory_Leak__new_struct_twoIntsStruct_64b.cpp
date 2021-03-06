/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoIntsStruct_64b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_64
{


void badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    struct _twoIntsStruct * * dataPtr = (struct _twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    struct _twoIntsStruct * data = (*dataPtr);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    struct _twoIntsStruct * * dataPtr = (struct _twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    struct _twoIntsStruct * data = (*dataPtr);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    struct _twoIntsStruct * * dataPtr = (struct _twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    struct _twoIntsStruct * data = (*dataPtr);
    /* FIX: Deallocate memory */
    delete data;
}


} /* close namespace */
