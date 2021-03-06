/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__semicolon_17.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: semicolon
 *    GoodSink: Removed statement that has no effect
 *    BadSink : A statement that has no effect
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__semicolon_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        /* FLAW: the statement has no effect */
        ;
        printLine("Hello from bad()");
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        /* FIX: Do not include a statement that has no effect */
        printLine("Hello from good()");
    }
}

void CWE398_Poor_Code_Quality__semicolon_17_good()
{
    good1();
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
    CWE398_Poor_Code_Quality__semicolon_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__semicolon_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
