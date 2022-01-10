/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_else_01.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_else
 *    GoodSink: Else statement contains code
 *    BadSink : An empty else statement has no effect
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__empty_else_01_bad()
{
    /* FLAW: An empty else statement has no effect */
    {
        int x;
        x = (rand() % 3);
        if (x == 0)
        {
            printLine("Inside the else statement");
        }
        else
        {
        }
    }
    printLine("Hello from bad()");
}



static void good1()
{
    /* FIX: Do not include an empty else statement */
    {
        int x;
        x = (rand() % 3);
        if (x == 0)
        {
            printLine("Inside the if statement");
        }
        else
        {
            printLine("Inside the else statement");
        }
    }
    printLine("Hello from good()");
}

void CWE398_Poor_Code_Quality__empty_else_01_good()
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
    CWE398_Poor_Code_Quality__empty_else_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_else_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
