/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_malloc_72b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_malloc_72
{


void badSink(vector<wchar_t *> dataVector)
{
    /* copy data out of dataVector */
    wchar_t * data = dataVector[2];
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<wchar_t *> dataVector)
{
    wchar_t * data = dataVector[2];
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<wchar_t *> dataVector)
{
    wchar_t * data = dataVector[2];
    /* FIX: Deallocate the memory using free() */
    free(data);
}


} /* close namespace */
