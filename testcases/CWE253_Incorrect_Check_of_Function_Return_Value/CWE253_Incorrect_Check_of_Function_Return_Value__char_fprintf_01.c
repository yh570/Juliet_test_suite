/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fprintf
 *    GoodSink: Correctly check if fprintf() failed
 *    BadSink : Incorrectly check if fprintf() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01_bad()
{
    /* FLAW: fprintf() might fail, in which case the return value will be negative, but
     * we are checking to see if the return value is 0 */
    if (fprintf(stdout, "%s\n", "string") == 0)
    {
        printLine("fprintf failed!");
    }
}



static void good1()
{
    /* FIX: check for the correct return value */
    if (fprintf(stdout, "%s\n", "string") < 0)
    {
        printLine("fprintf failed!");
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
