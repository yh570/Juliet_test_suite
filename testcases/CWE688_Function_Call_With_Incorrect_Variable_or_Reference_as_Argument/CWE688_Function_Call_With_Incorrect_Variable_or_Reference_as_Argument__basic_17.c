/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_17.c
Label Definition File: CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 688 Function Call With Incorrect Variable or Reference as Argument
 * Sinks:
 *    GoodSink: Use the correct format to print a string
 *    BadSink : Use a string format to print an int
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 100


void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            char dest[DEST_SIZE];
            int intFive = 5;
            /* FLAW: int argument passed, expecting string argument */
            sprintf(dest, "%s", intFive);
            printLine(dest);
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
            char dest[DEST_SIZE];
            int intFive = 5;
            /* FIX: use the correct format string */
            sprintf(dest, "%d", intFive);
            printLine(dest);
        }
    }
}

void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_17_good()
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
    CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
