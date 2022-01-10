/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_16.c
Label Definition File: CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 685 Function Call With Incorrect Number of Arguments
 * Sinks:
 *    GoodSink: Use the correct number of arguments
 *    BadSink : Incorrect number of arguments
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 100 /* maintenance note: ensure this is > 2*SOURCE_STRING to avoid buffer overflow issues */
#define SOURCE_STRING "AAA"


void CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_16_bad()
{
    while(1)
    {
        {
            char dest[DEST_SIZE];
            /* FLAW: Incorrect number of arguments */
            sprintf(dest, "%s %s", SOURCE_STRING);
            printLine(dest);
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
            char dest[DEST_SIZE];
            /* FIX: Use the correct number of arguments */
            sprintf(dest, "%s %s", SOURCE_STRING, SOURCE_STRING);
            printLine(dest);
        }
        break;
    }
}

void CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_16_good()
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
    CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE685_Function_Call_With_Incorrect_Number_of_Arguments__basic_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
