/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_char_calloc_67b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_char_calloc_67
{

typedef struct _structType
{
    char * structFirst;
} structType;


void badSink(structType myStruct)
{
    char * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct)
{
    char * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(structType myStruct)
{
    char * data = myStruct.structFirst;
    /* FIX: Deallocate the memory using free() */
    free(data);
}


} /* close namespace */
