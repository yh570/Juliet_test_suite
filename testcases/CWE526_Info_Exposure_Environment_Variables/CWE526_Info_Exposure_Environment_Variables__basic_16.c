/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE526_Info_Exposure_Environment_Variables__basic_16.c
Label Definition File: CWE526_Info_Exposure_Environment_Variables__basic.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 526 Information Exposure Through Environment Variables
 * Sinks:
 *    GoodSink: Print a generic error message to the console
 *    BadSink : Expose the contents of an environment variable to the console
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE526_Info_Exposure_Environment_Variables__basic_16_bad()
{
    while(1)
    {
        /* FLAW: environment variable exposed */
        printLine(getenv("PATH"));
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        /* FIX: error message is general */
        printLine("Not in path");
        break;
    }
}

void CWE526_Info_Exposure_Environment_Variables__basic_16_good()
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
    CWE526_Info_Exposure_Environment_Variables__basic_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE526_Info_Exposure_Environment_Variables__basic_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
