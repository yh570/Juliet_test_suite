/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_postdec_17.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__short_rand_postdec_17_bad()
{
    int i,j;
    short data;
    data = 0;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            short result = data;
            printIntLine(result);
        }
    }
}



/* goodB2G() - use badsource and goodsink in the for statements */
static void goodB2G()
{
    int i,k;
    short data;
    data = 0;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    for(k = 0; k < 1; k++)
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > SHRT_MIN)
        {
            data--;
            short result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B() - use goodsource and badsink in the for statements */
static void goodG2B()
{
    int h,j;
    short data;
    data = 0;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            short result = data;
            printIntLine(result);
        }
    }
}

void CWE191_Integer_Underflow__short_rand_postdec_17_good()
{
    goodB2G();
    goodG2B();
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
    CWE191_Integer_Underflow__short_rand_postdec_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_rand_postdec_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
