/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_63b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_63
{


void badSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    /* FIX: Deallocate the memory using delete */
    delete data;
}


} /* close namespace */
