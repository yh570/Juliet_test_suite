/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__sqrt_09.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: sqrt
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if sqrt() failed
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#include <math.h>


void CWE391_Unchecked_Error_Condition__sqrt_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            double doubleNumber;
            doubleNumber = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(doubleNumber);
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
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* FIX: Check errno to see if sqrt() failed */
            if (errno == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(doubleNumber);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* FIX: Check errno to see if sqrt() failed */
            if (errno == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(doubleNumber);
        }
    }
}

void CWE391_Unchecked_Error_Condition__sqrt_09_good()
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
    CWE391_Unchecked_Error_Condition__sqrt_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__sqrt_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
