/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_postdec_12.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__short_rand_postdec_12_bad()
{
    short data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            short result = data;
            printIntLine(result);
        }
    }
    else
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



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    short data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    else
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    if(globalReturnsTrueOrFalse())
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
    else
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

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    short data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            short result = data;
            printIntLine(result);
        }
    }
    else
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            short result = data;
            printIntLine(result);
        }
    }
}

void CWE191_Integer_Underflow__short_rand_postdec_12_good()
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
    CWE191_Integer_Underflow__short_rand_postdec_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_rand_postdec_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
