/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_postdec_18.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__int64_t_rand_postdec_18_bad()
{
    int64_t data;
    data = 0LL;
    goto source;
source:
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
    goto sink;
sink:
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        int64_t result = data;
        printLongLongLine(result);
    }
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    goto source;
source:
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
    goto sink;
sink:
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > LLONG_MIN)
    {
        data--;
        int64_t result = data;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    goto source;
source:
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    goto sink;
sink:
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        int64_t result = data;
        printLongLongLine(result);
    }
}

void CWE191_Integer_Underflow__int64_t_rand_postdec_18_good()
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
    CWE191_Integer_Underflow__int64_t_rand_postdec_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int64_t_rand_postdec_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
