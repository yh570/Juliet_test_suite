/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fputs
 *    GoodSink: Correctly check if fputs() failed
 *    BadSink : Incorrectly check if fputs() failed
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16_bad()
{
    while(1)
    {
        /* FLAW: fputs() might fail, in which case the return value will be EOF (-1), but
         * we are checking to see if the return value is 0 */
        if (fputs("string", stdout) == 0)
        {
            printLine("fputs failed!");
        }
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        /* FIX: check for the correct return value */
        if (fputs("string", stdout) == EOF)
        {
            printLine("fputs failed!");
        }
        break;
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fputs_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
