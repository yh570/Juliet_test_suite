/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_63b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE415_Double_Free__malloc_free_int_63b_badSink(int * * dataPtr)
{
    int * data = *dataPtr;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_int_63b_goodG2BSink(int * * dataPtr)
{
    int * data = *dataPtr;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_int_63b_goodB2GSink(int * * dataPtr)
{
    int * data = *dataPtr;
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

