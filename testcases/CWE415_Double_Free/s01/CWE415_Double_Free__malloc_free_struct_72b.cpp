/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_struct_72b.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__malloc_free_struct_72
{


void badSink(vector<twoIntsStruct *> dataVector)
{
    /* copy data out of dataVector */
    twoIntsStruct * data = dataVector[2];
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<twoIntsStruct *> dataVector)
{
    twoIntsStruct * data = dataVector[2];
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<twoIntsStruct *> dataVector)
{
    twoIntsStruct * data = dataVector[2];
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
