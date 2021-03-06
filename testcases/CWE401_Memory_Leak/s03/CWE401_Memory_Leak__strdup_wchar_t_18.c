/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_18.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE401_Memory_Leak__strdup_wchar_t_18_bad()
{
    wchar_t * data;
    data = NULL;
    goto source;
source:
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    goto sink;
sink:
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    wchar_t * data;
    data = NULL;
    goto source;
source:
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    goto sink;
sink:
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    goto source;
source:
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize then use data */
    wcscpy(data, L"a string");
    printWLine(data);
    goto sink;
sink:
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__strdup_wchar_t_18_good()
{
    goodB2G();
    goodG2B();
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
    CWE401_Memory_Leak__strdup_wchar_t_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE401_Memory_Leak__strdup_wchar_t_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
