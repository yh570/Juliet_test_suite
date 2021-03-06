/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_class_calloc_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_class_calloc_61
{


TwoIntsClass * badSource(TwoIntsClass * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (TwoIntsClass *)calloc(100, sizeof(TwoIntsClass));
    if (data == NULL) {exit(-1);}
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
TwoIntsClass * goodG2BSource(TwoIntsClass * data)
{
    /* FIX: Allocate memory from the heap using new */
    data = new TwoIntsClass;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
TwoIntsClass * goodB2GSource(TwoIntsClass * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (TwoIntsClass *)calloc(100, sizeof(TwoIntsClass));
    if (data == NULL) {exit(-1);}
    return data;
}


} /* close namespace */
