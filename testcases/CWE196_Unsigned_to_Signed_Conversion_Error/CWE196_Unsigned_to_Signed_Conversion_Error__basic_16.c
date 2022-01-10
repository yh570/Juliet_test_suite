/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE196_Unsigned_to_Signed_Conversion_Error__basic_16.c
Label Definition File: CWE196_Unsigned_to_Signed_Conversion_Error__basic.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 196 Unsigned To Signed Conversion Error
 * Sinks:
 *    GoodSink: Don't allow very large values of intUnsigned
 *    BadSink : Convert a possibly large unsigned int (larger than INT_MAX) to an int
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE196_Unsigned_to_Signed_Conversion_Error__basic_16_bad()
{
    while(1)
    {
        {
            unsigned intUnsigned;
            int intSigned;
            intUnsigned = rand();
            if (rand() % 2 == 0)
            {
                intUnsigned = UINT_MAX - intUnsigned;
            }
            /* FLAW: intUnsigned could be very large, in which case intSigned will be negative */
            intSigned = intUnsigned;
            printIntLine(intSigned);
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
            unsigned intUnsigned;
            int intSigned;
            intUnsigned = rand();
            if (rand() % 2 == 0)
            {
                intUnsigned = UINT_MAX - intUnsigned;
            }
            /* FIX: don't allow very large values of intUnsigned */
            if (intUnsigned > INT_MAX)
            {
                exit(1);
            }
            intSigned = intUnsigned;
            printIntLine(intSigned);
        }
        break;
    }
}

void CWE196_Unsigned_to_Signed_Conversion_Error__basic_16_good()
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
    CWE196_Unsigned_to_Signed_Conversion_Error__basic_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE196_Unsigned_to_Signed_Conversion_Error__basic_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
