/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_class_calloc_68b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_class_calloc_68
{

extern TwoIntsClass * badData;
extern TwoIntsClass * goodG2BData;
extern TwoIntsClass * goodB2GData;


void badSink()
{
    TwoIntsClass * data = badData;
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink()
{
    TwoIntsClass * data = goodG2BData;
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink()
{
    TwoIntsClass * data = goodB2GData;
    /* FIX: Free memory using free() */
    free(data);
}


} /* close namespace */
