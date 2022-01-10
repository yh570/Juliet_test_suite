/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__sqrt_16.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: sqrt
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if sqrt() failed
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#include <math.h>


void CWE391_Unchecked_Error_Condition__sqrt_16_bad()
{
    while(1)
    {
        {
            double doubleNumber;
            doubleNumber = (double)sqrt((double)-1);
            /* FLAW: Do not check to see if sqrt() failed */
            printDoubleLine(doubleNumber);
        }
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
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
        break;
    }
}

void CWE391_Unchecked_Error_Condition__sqrt_16_good()
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
    CWE391_Unchecked_Error_Condition__sqrt_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__sqrt_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
