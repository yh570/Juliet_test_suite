/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fputc
 *    GoodSink: Correctly check if fputc() failed
 *    BadSink : Incorrectly check if fputc() failed
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: fputc() might fail, in which case the return value will be EOF (-1), but
         * we are checking to see if the return value is 0 */
        if (fputc((int)'A', stdout) == 0)
        {
            printLine("fputc failed!");
        }
    }
}



/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check for the correct return value */
        if (fputc((int)'A', stdout) == EOF)
        {
            printLine("fputc failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: check for the correct return value */
        if (fputc((int)'A', stdout) == EOF)
        {
            printLine("fputc failed!");
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fputc_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
