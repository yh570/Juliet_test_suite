/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_81_goodG2B.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_81.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_81
{

void CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_81_goodG2B::action(char * data) const
{
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}

}
