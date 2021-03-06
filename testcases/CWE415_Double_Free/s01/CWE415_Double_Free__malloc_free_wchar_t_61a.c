/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_61a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
wchar_t * CWE415_Double_Free__malloc_free_wchar_t_61b_badSource(wchar_t * data);

void CWE415_Double_Free__malloc_free_wchar_t_61_bad()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE415_Double_Free__malloc_free_wchar_t_61b_badSource(data);
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE415_Double_Free__malloc_free_wchar_t_61b_goodG2BSource(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE415_Double_Free__malloc_free_wchar_t_61b_goodG2BSource(data);
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
wchar_t * CWE415_Double_Free__malloc_free_wchar_t_61b_goodB2GSource(wchar_t * data);

static void goodB2G()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE415_Double_Free__malloc_free_wchar_t_61b_goodB2GSource(data);
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

void CWE415_Double_Free__malloc_free_wchar_t_61_good()
{
    goodG2B();
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE415_Double_Free__malloc_free_wchar_t_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_wchar_t_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
