/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoIntsStruct_72b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_72
{


void badSink(vector<struct _twoIntsStruct *> dataVector)
{
    /* copy data out of dataVector */
    struct _twoIntsStruct * data = dataVector[2];
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<struct _twoIntsStruct *> dataVector)
{
    struct _twoIntsStruct * data = dataVector[2];
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<struct _twoIntsStruct *> dataVector)
{
    struct _twoIntsStruct * data = dataVector[2];
    /* FIX: Deallocate memory */
    delete data;
}


} /* close namespace */
