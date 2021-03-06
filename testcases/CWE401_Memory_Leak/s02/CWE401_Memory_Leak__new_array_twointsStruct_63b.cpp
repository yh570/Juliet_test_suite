/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsStruct_63b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_twointsStruct_63
{


void badSink(twoIntsStruct * * dataPtr)
{
    twoIntsStruct * data = *dataPtr;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(twoIntsStruct * * dataPtr)
{
    twoIntsStruct * data = *dataPtr;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(twoIntsStruct * * dataPtr)
{
    twoIntsStruct * data = *dataPtr;
    /* FIX: Deallocate memory */
    delete[] data;
}


} /* close namespace */
