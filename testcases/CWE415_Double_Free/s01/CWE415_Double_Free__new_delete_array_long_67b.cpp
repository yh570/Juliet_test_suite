/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_67b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_long_67
{

typedef struct _structType
{
    long * structFirst;
} structType;


void badSink(structType myStruct)
{
    long * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct)
{
    long * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(structType myStruct)
{
    long * data = myStruct.structFirst;
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
