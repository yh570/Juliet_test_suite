/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__strtol_05.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: strtol
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if strtol() failed
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */


void CWE391_Unchecked_Error_Condition__strtol_05_bad()
{
    if(staticTrue)
    {
        {
            long longNumber;
            longNumber = strtol("0xfffffffff", NULL, 0);
            /* FLAW: Do not check to see if strtol() failed */
            printf("%li\n", longNumber);
        }
    }
}



/* good1() uses if(staticFalse) instead of if(staticTrue) */
static void good1()
{
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            long longNumber;
            errno = 0; /* set errno to zero before calling strtol(), which can change its value */
            longNumber = strtol("0xfffffffff", NULL, 0);
            /* FIX: Check errno to see if strtol() failed */
            if (errno == ERANGE)
            {
                printLine("strtol() failed");
                exit(1);
            }
            printf("%li\n", longNumber);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticTrue)
    {
        {
            long longNumber;
            errno = 0; /* set errno to zero before calling strtol(), which can change its value */
            longNumber = strtol("0xfffffffff", NULL, 0);
            /* FIX: Check errno to see if strtol() failed */
            if (errno == ERANGE)
            {
                printLine("strtol() failed");
                exit(1);
            }
            printf("%li\n", longNumber);
        }
    }
}

void CWE391_Unchecked_Error_Condition__strtol_05_good()
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
    CWE391_Unchecked_Error_Condition__strtol_05_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__strtol_05_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
