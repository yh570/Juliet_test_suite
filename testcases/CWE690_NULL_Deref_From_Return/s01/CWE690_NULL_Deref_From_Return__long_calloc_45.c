/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_calloc_45.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static long * CWE690_NULL_Deref_From_Return__long_calloc_45_badData;
static long * CWE690_NULL_Deref_From_Return__long_calloc_45_goodB2GData;


static void badSink()
{
    long * data = CWE690_NULL_Deref_From_Return__long_calloc_45_badData;
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5L;
    printLongLine(data[0]);
    free(data);
}

void CWE690_NULL_Deref_From_Return__long_calloc_45_bad()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
    CWE690_NULL_Deref_From_Return__long_calloc_45_badData = data;
    badSink();
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    long * data = CWE690_NULL_Deref_From_Return__long_calloc_45_goodB2GData;
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5L;
        printLongLine(data[0]);
        free(data);
    }
}

static void goodB2G()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
    CWE690_NULL_Deref_From_Return__long_calloc_45_goodB2GData = data;
    goodB2GSink();
}

void CWE690_NULL_Deref_From_Return__long_calloc_45_good()
{
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
    CWE690_NULL_Deref_From_Return__long_calloc_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__long_calloc_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
