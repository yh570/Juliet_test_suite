/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE483_Incorrect_Block_Delimitation__semicolon_15.c
Label Definition File: CWE483_Incorrect_Block_Delimitation.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 483 Incorrect Block Delimitation
 * Sinks: semicolon
 *    GoodSink: Absence of suspicious semicolon
 *    BadSink : Suspicious semicolon before the if statement brace
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"


void CWE483_Incorrect_Block_Delimitation__semicolon_15_bad()
{
    switch(6)
    {
    case 6:
    {
        int x = (rand() % 3);
        int y = 0;
        /* FLAW: Suspicious semicolon before the if statement brace */
        if (x == 0);
        {
            printLine("x == 0");
            y = 1;
        }
        if (y)
        {
            printLine("x was 0\n");
        }
    }
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
    {
        int x = (rand() % 3);
        int y = 0;
        /* FIX: Removed suspicious semicolon before the if statement brace */
        if (x == 0)
        {
            printLine("x == 0");
            y = 1;
        }
        if (y)
        {
            printLine("x was 0\n");
        }
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        int x = (rand() % 3);
        int y = 0;
        /* FIX: Removed suspicious semicolon before the if statement brace */
        if (x == 0)
        {
            printLine("x == 0");
            y = 1;
        }
        if (y)
        {
            printLine("x was 0\n");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE483_Incorrect_Block_Delimitation__semicolon_15_good()
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
    CWE483_Incorrect_Block_Delimitation__semicolon_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE483_Incorrect_Block_Delimitation__semicolon_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
