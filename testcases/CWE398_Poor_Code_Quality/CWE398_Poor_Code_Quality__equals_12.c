/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__equals_12.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: equals
 *    GoodSink: Set a variable equal to another variable
 *    BadSink : Setting a variable equal to itself has no effect
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__equals_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            int intOne = 1;
            printIntLine(intOne);
            /* FLAW: the statement has no effect */
            intOne = intOne;
            printIntLine(intOne);
        }
    }
    else
    {
        {
            int intOne = 1, intFive = 5;
            printIntLine(intOne);
            /* FIX: Do not include a statement that has no effect */
            intOne = intFive;
            printIntLine(intOne);
        }
    }
}



/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            int intOne = 1, intFive = 5;
            printIntLine(intOne);
            /* FIX: Do not include a statement that has no effect */
            intOne = intFive;
            printIntLine(intOne);
        }
    }
    else
    {
        {
            int intOne = 1, intFive = 5;
            printIntLine(intOne);
            /* FIX: Do not include a statement that has no effect */
            intOne = intFive;
            printIntLine(intOne);
        }
    }
}

void CWE398_Poor_Code_Quality__equals_12_good()
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
    CWE398_Poor_Code_Quality__equals_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__equals_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
