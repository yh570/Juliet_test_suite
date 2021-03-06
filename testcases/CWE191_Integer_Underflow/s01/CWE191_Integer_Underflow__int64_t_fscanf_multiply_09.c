/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_multiply_09.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"


void CWE191_Integer_Underflow__int64_t_fscanf_multiply_09_bad()
{
    int64_t data;
    data = 0LL;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%" SCNd64, &data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodB2G1()
{
    int64_t data;
    data = 0LL;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%" SCNd64, &data);
    }
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > (LLONG_MIN/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
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
    int64_t data;
    data = 0LL;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%" SCNd64, &data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > (LLONG_MIN/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
            }
            else
            {
                printLine("data value is too small to perform multiplication.");
            }
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodG2B1()
{
    int64_t data;
    data = 0LL;
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(GLOBAL_CONST_TRUE)
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int64_t data;
    data = 0LL;
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(GLOBAL_CONST_TRUE)
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}

void CWE191_Integer_Underflow__int64_t_fscanf_multiply_09_good()
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
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
