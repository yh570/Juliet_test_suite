/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_multiply_18.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__int_min_multiply_18_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use the minimum value for this type */
    data = INT_MIN;
    goto sink;
sink:
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
        int result = data * 2;
        printIntLine(result);
    }
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use the minimum value for this type */
    data = INT_MIN;
    goto sink;
sink:
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > (INT_MIN/2))
        {
            int result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too small to perform multiplication.");
        }
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    goto source;
source:
    /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
    data = -2;
    goto sink;
sink:
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
        int result = data * 2;
        printIntLine(result);
    }
}

void CWE191_Integer_Underflow__int_min_multiply_18_good()
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
    CWE191_Integer_Underflow__int_min_multiply_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_min_multiply_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
