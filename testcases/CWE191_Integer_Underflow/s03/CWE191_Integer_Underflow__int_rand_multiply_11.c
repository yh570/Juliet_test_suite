/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_rand_multiply_11.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__int_rand_multiply_11_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    if(globalReturnsTrue())
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
            int result = data * 2;
            printIntLine(result);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second globalReturnsTrue() to globalReturnsFalse() */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
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
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    if(globalReturnsTrue())
    {
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
}

/* goodG2B1() - use goodsource and badsink by changing the first globalReturnsTrue() to globalReturnsFalse() */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
        data = -2;
    }
    if(globalReturnsTrue())
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
            int result = data * 2;
            printIntLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalReturnsTrue())
    {
        /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
        data = -2;
    }
    if(globalReturnsTrue())
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
            int result = data * 2;
            printIntLine(result);
        }
    }
}

void CWE191_Integer_Underflow__int_rand_multiply_11_good()
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
    CWE191_Integer_Underflow__int_rand_multiply_11_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_rand_multiply_11_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
