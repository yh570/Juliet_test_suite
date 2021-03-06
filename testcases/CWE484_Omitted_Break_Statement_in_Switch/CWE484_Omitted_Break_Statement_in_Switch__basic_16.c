/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE484_Omitted_Break_Statement_in_Switch__basic_16.c
Label Definition File: CWE484_Omitted_Break_Statement_in_Switch__basic.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 484 Omitted Break Statement in Switch
 * Sinks:
 *    GoodSink: Use breaks at the end of cases to prevent fall through
 *    BadSink : Missing break in first case
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE484_Omitted_Break_Statement_in_Switch__basic_16_bad()
{
    while(1)
    {
        {
            int x = (rand() % 3);
            /* FLAW: Missing break in first case */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
            default:
                printLine("Invalid Number");
                break;
            }
        }
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        {
            int x = (rand() % 3);
            /* FIX: Use break in all cases that you do not intend "fall-through"
             * behavior */
            switch (x)
            {
            case 0:
                printLine("0");
                break;
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
            default:
                printLine("Invalid Number");
                break;
            }
        }
        break;
    }
}

void CWE484_Omitted_Break_Statement_in_Switch__basic_16_good()
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
    CWE484_Omitted_Break_Statement_in_Switch__basic_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE484_Omitted_Break_Statement_in_Switch__basic_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
