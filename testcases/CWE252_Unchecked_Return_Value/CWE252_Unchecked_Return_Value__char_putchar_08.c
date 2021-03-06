/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_putchar_08.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: putchar
 *    GoodSink: Check if putchar() fails
 *    BadSink : Do not check if putchar() fails
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}


void CWE252_Unchecked_Return_Value__char_putchar_08_bad()
{
    if(staticReturnsTrue())
    {
        /* FLAW: Do not check the return value */
        putchar((int)'A');
    }
}



/* good1() uses if(staticReturnsFalse()) instead of if(staticReturnsTrue()) */
static void good1()
{
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check the return value */
        if (putchar((int)'A') == EOF)
        {
            printLine("putchar failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticReturnsTrue())
    {
        /* FIX: check the return value */
        if (putchar((int)'A') == EOF)
        {
            printLine("putchar failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_putchar_08_good()
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
    CWE252_Unchecked_Return_Value__char_putchar_08_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_putchar_08_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
