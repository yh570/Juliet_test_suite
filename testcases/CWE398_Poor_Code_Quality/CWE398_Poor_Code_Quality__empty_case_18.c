/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_case_18.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_case
 *    GoodSink: Case statement contains code
 *    BadSink : An empty case statement has no effect
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__empty_case_18_bad()
{
    goto sink;
sink:
    /* FLAW: An empty case statement has no effect */
    {
        int x = (rand() % 3);
        switch (x)
        {
        case 0:
            break;
        }
    }
    printLine("Hello from bad()");
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    /* FIX: Do not include an empty case statement */
    {
        int x = (rand() % 3);
        switch (x)
        {
        case 0:
            printLine("Inside the case statement");
            break;
        }
    }
    printLine("Hello from good()");
}

void CWE398_Poor_Code_Quality__empty_case_18_good()
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
    CWE398_Poor_Code_Quality__empty_case_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_case_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
