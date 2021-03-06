/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_class_51b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-51b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using free()
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_class_51
{


void badSink(TwoIntsClass * data)
{
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(TwoIntsClass * data)
{
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(TwoIntsClass * data)
{
    /* FIX: Deallocate the memory using delete */
    delete data;
}


} /* close namespace */
