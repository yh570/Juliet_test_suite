/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_fputs_13.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fputs
 *    GoodSink: Check if fputs() fails
 *    BadSink : Do not check if fputs() fails
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE252_Unchecked_Return_Value__char_fputs_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FLAW: Do not check the return value */
        fputs("string", stdout);
    }
}



/* good1() uses if(GLOBAL_CONST_FIVE!=5) instead of if(GLOBAL_CONST_FIVE==5) */
static void good1()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check the return value */
        if (fputs("string", stdout) == EOF)
        {
            printLine("fputs failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FIX: check the return value */
        if (fputs("string", stdout) == EOF)
        {
            printLine("fputs failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_fputs_13_good()
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
    CWE252_Unchecked_Return_Value__char_fputs_13_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_fputs_13_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
