/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_sub_02.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__short_rand_sub_02_bad()
{
    short data;
    data = 0;
    if(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    if(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            short result = data - 1;
            printIntLine(result);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second 1 to 0 */
static void goodB2G1()
{
    short data;
    data = 0;
    if(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > SHRT_MIN)
        {
            short result = data - 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform subtraction.");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    short data;
    data = 0;
    if(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    if(1)
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > SHRT_MIN)
        {
            short result = data - 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform subtraction.");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 1 to 0 */
static void goodG2B1()
{
    short data;
    data = 0;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            short result = data - 1;
            printIntLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    short data;
    data = 0;
    if(1)
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            short result = data - 1;
            printIntLine(result);
        }
    }
}

void CWE191_Integer_Underflow__short_rand_sub_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE191_Integer_Underflow__short_rand_sub_02_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_rand_sub_02_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
