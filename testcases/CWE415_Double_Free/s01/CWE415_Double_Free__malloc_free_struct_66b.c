/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_struct_66b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE415_Double_Free__malloc_free_struct_66b_badSink(twoIntsStruct * dataArray[])
{
    /* copy data out of dataArray */
    twoIntsStruct * data = dataArray[2];
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_struct_66b_goodG2BSink(twoIntsStruct * dataArray[])
{
    twoIntsStruct * data = dataArray[2];
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_struct_66b_goodB2GSink(twoIntsStruct * dataArray[])
{
    twoIntsStruct * data = dataArray[2];
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

