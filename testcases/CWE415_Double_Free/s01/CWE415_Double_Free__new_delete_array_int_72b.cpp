/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int_72b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__new_delete_array_int_72
{


void badSink(vector<int *> dataVector)
{
    /* copy data out of dataVector */
    int * data = dataVector[2];
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<int *> dataVector)
{
    int * data = dataVector[2];
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<int *> dataVector)
{
    int * data = dataVector[2];
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
