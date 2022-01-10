/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE526_Info_Exposure_Environment_Variables__basic_01.c
Label Definition File: CWE526_Info_Exposure_Environment_Variables__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 526 Information Exposure Through Environment Variables
 * Sinks:
 *    GoodSink: Print a generic error message to the console
 *    BadSink : Expose the contents of an environment variable to the console
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


void CWE526_Info_Exposure_Environment_Variables__basic_01_bad()
{
    /* FLAW: environment variable exposed */
    printLine(getenv("PATH"));
}



static void good1()
{
    /* FIX: error message is general */
    printLine("Not in path");
}

void CWE526_Info_Exposure_Environment_Variables__basic_01_good()
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
    CWE526_Info_Exposure_Environment_Variables__basic_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE526_Info_Exposure_Environment_Variables__basic_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
