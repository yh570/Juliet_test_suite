/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_53b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-53b.tmpl.cpp
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

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_53
{


/* bad function declaration */
void badSink_c(wchar_t * data);

void badSink_b(wchar_t * data)
{
    badSink_c(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_c(wchar_t * data);

void goodG2BSink_b(wchar_t * data)
{
    goodG2BSink_c(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_c(wchar_t * data);

void goodB2GSink_b(wchar_t * data)
{
    goodB2GSink_c(data);
}


} /* close namespace */
