/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_class_72b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using free()
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_class_72
{


void badSink(vector<TwoIntsClass *> dataVector)
{
    /* copy data out of dataVector */
    TwoIntsClass * data = dataVector[2];
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<TwoIntsClass *> dataVector)
{
    TwoIntsClass * data = dataVector[2];
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<TwoIntsClass *> dataVector)
{
    TwoIntsClass * data = dataVector[2];
    /* FIX: Deallocate the memory using delete */
    delete data;
}


} /* close namespace */
