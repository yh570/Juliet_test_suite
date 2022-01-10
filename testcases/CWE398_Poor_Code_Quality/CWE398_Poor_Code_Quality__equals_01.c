/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__equals_01.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: equals
 *    GoodSink: Set a variable equal to another variable
 *    BadSink : Setting a variable equal to itself has no effect
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__equals_01_bad()
{
    {
        int intOne = 1;
        printIntLine(intOne);
        /* FLAW: the statement has no effect */
        intOne = intOne;
        printIntLine(intOne);
    }
}



static void good1()
{
    {
        int intOne = 1, intFive = 5;
        printIntLine(intOne);
        /* FIX: Do not include a statement that has no effect */
        intOne = intFive;
        printIntLine(intOne);
    }
}

void CWE398_Poor_Code_Quality__equals_01_good()
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
    CWE398_Poor_Code_Quality__equals_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__equals_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
