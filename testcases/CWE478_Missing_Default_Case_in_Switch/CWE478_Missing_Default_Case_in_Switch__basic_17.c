/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE478_Missing_Default_Case_in_Switch__basic_17.c
Label Definition File: CWE478_Missing_Default_Case_in_Switch__basic.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 478 Missing Default Case in Switch
 * Sinks:
 *    GoodSink: Use default case in switch statement
 *    BadSink : No default case in a switch statement
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


void CWE478_Missing_Default_Case_in_Switch__basic_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            const char *charString = "shouldn\'t see this value";
            int x;
            x = (rand() % 3);
            switch (x)
            {
            case 0:
                charString = "0";
                break;
            case 1:
                charString = "1";
                break;
                /* FLAW: x could be 2, and there is no 'default' case for that */
            }
            printLine(charString);
        }
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            const char *charString = "shouldn\'t see this value";
            int x;
            x = (rand() % 3);
            switch (x)
            {
            case 0:
                charString = "0";
                break;
            case 1:
                charString = "1";
                break;
                /* FIX: provide a 'default' case for other values */
            default:
                return;
            }
            printLine(charString);
        }
    }
}

void CWE478_Missing_Default_Case_in_Switch__basic_17_good()
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
    CWE478_Missing_Default_Case_in_Switch__basic_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE478_Missing_Default_Case_in_Switch__basic_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
