/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_07.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value__w32.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: ImpersonateSelf
 *    GoodSink: Correctly check if ImpersonateSelf() fails
 *    BadSink : Incorrectly check if ImpersonateSelf() fails
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32")

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


void CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_07_bad()
{
    if(staticFive==5)
    {
        /* FLAW: ImpersonateSelf() could fail and would return 0 (false), but we are checking to see
         * if the return value is greater than zero (true) */
        if (ImpersonateSelf(SecurityImpersonation) > 0)
        {
            exit(1);
        }
    }
}



/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
static void good1()
{
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check for the correct return value */
        if (!ImpersonateSelf(SecurityImpersonation))
        {
            exit(1);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        /* FIX: check for the correct return value */
        if (!ImpersonateSelf(SecurityImpersonation))
        {
            exit(1);
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_07_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_07_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_07_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
