/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_66a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-66a.tmpl.c
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


/* bad function declaration */
void CWE415_Double_Free__malloc_free_long_66b_badSink(long * dataArray[]);

void CWE415_Double_Free__malloc_free_long_66_bad()
{
    long * data;
    long * dataArray[5];
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    /* put data in array */
    dataArray[2] = data;
    CWE415_Double_Free__malloc_free_long_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_long_66b_goodG2BSink(long * dataArray[]);

static void goodG2B()
{
    long * data;
    long * dataArray[5];
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    dataArray[2] = data;
    CWE415_Double_Free__malloc_free_long_66b_goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_long_66b_goodB2GSink(long * dataArray[]);

static void goodB2G()
{
    long * data;
    long * dataArray[5];
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    dataArray[2] = data;
    CWE415_Double_Free__malloc_free_long_66b_goodB2GSink(dataArray);
}

void CWE415_Double_Free__malloc_free_long_66_good()
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
    CWE415_Double_Free__malloc_free_long_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_long_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
