/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_long_74b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_long_74
{


void badSink(map<int, long *> dataMap)
{
    /* copy data out of dataMap */
    long * data = dataMap[2];
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, long *> dataMap)
{
    long * data = dataMap[2];
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, long *> dataMap)
{
    long * data = dataMap[2];
    /* FIX: Deallocate the memory using delete [] */
    delete [] data;
}


} /* close namespace */
