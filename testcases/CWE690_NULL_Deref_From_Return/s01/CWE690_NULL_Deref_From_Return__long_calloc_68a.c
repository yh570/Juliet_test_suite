/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_calloc_68a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

long * CWE690_NULL_Deref_From_Return__long_calloc_68_badDataForBadSink;

long * CWE690_NULL_Deref_From_Return__long_calloc_68_badDataForGoodSink;


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__long_calloc_68b_badSink();

void CWE690_NULL_Deref_From_Return__long_calloc_68_bad()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
    CWE690_NULL_Deref_From_Return__long_calloc_68_badDataForBadSink = data;
    CWE690_NULL_Deref_From_Return__long_calloc_68b_badSink();
}



/* good function declarations */
void CWE690_NULL_Deref_From_Return__long_calloc_68b_goodB2GSink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
    CWE690_NULL_Deref_From_Return__long_calloc_68_badDataForGoodSink = data;
    CWE690_NULL_Deref_From_Return__long_calloc_68b_goodB2GSink();
}

void CWE690_NULL_Deref_From_Return__long_calloc_68_good()
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
    CWE690_NULL_Deref_From_Return__long_calloc_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__long_calloc_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
