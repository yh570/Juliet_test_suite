/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_puts_03.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: puts
 *    GoodSink: Check if puts() fails
 *    BadSink : Do not check if puts() fails
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define PUTS puts
#else
#define PUTS puts
#endif


void CWE252_Unchecked_Return_Value__char_puts_03_bad()
{
    if(5==5)
    {
        /* FLAW: Do not check the return value */
        PUTS("string");
    }
}



/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check the return value */
        if (PUTS("string") == EOF)
        {
            printLine("puts failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        /* FIX: check the return value */
        if (PUTS("string") == EOF)
        {
            printLine("puts failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_puts_03_good()
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
    CWE252_Unchecked_Return_Value__char_puts_03_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_puts_03_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
