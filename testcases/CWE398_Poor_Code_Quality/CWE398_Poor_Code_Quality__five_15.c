/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__five_15.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: five
 *    GoodSink: Removed statement that has no effect
 *    BadSink : A statement that has no effect
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__five_15_bad()
{
    switch(6)
    {
    case 6:
        /* FLAW: the statement has no effect */
        5;
        printLine("Hello from bad()");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}



/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
        /* FIX: Do not include a statement that has no effect */
        printLine("Hello from good()");
        break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
        /* FIX: Do not include a statement that has no effect */
        printLine("Hello from good()");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE398_Poor_Code_Quality__five_15_good()
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
    CWE398_Poor_Code_Quality__five_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__five_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
