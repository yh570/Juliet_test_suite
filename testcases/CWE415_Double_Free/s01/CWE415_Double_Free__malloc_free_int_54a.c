/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_54a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE415_Double_Free__malloc_free_int_54b_badSink(int * data);

void CWE415_Double_Free__malloc_free_int_54_bad()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_int_54b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_int_54b_goodG2BSink(int * data);

static void goodG2B()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    CWE415_Double_Free__malloc_free_int_54b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_int_54b_goodB2GSink(int * data);

static void goodB2G()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_int_54b_goodB2GSink(data);
}

void CWE415_Double_Free__malloc_free_int_54_good()
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
    CWE415_Double_Free__malloc_free_int_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_int_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
