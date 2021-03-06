/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int_53d.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-53d.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int_53
{


void badSink_d(int * data)
{
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(int * data)
{
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_d(int * data)
{
    /* FIX: Deallocate the memory using delete [] */
    delete [] data;
}


} /* close namespace */
