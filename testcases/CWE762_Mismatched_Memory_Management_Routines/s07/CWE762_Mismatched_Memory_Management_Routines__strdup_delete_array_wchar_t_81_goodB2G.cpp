/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_81_goodB2G.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_81.h"

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_81
{

void CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_81_goodB2G::action(wchar_t * data) const
{
    /* FIX: Deallocate the memory using free() */
    free(data);
}

}
