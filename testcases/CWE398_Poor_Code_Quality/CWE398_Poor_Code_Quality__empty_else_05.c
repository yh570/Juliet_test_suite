/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_else_05.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_else
 *    GoodSink: Else statement contains code
 *    BadSink : An empty else statement has no effect
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */


void CWE398_Poor_Code_Quality__empty_else_05_bad()
{
    if(staticTrue)
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
}



/* good1() uses if(staticFalse) instead of if(staticTrue) */
static void good1()
{
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
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
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticTrue)
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
}

void CWE398_Poor_Code_Quality__empty_else_05_good()
{
    good1();
    good2();
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
    CWE398_Poor_Code_Quality__empty_else_05_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_else_05_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
