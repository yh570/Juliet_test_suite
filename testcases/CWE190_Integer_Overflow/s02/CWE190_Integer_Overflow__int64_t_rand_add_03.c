/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_add_03.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__int64_t_rand_add_03_bad()
{
    int64_t data;
    data = 0LL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (int64_t)RAND64();
    }
    if(5==5)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int64_t result = data + 1;
            printLongLongLine(result);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    int64_t data;
    data = 0LL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (int64_t)RAND64();
    }
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < LLONG_MAX)
        {
            int64_t result = data + 1;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int64_t data;
    data = 0LL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (int64_t)RAND64();
    }
    if(5==5)
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < LLONG_MAX)
        {
            int64_t result = data + 1;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    int64_t data;
    data = 0LL;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    if(5==5)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int64_t result = data + 1;
            printLongLongLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int64_t data;
    data = 0LL;
    if(5==5)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    if(5==5)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int64_t result = data + 1;
            printLongLongLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int64_t_rand_add_03_good()
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
    CWE190_Integer_Overflow__int64_t_rand_add_03_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_rand_add_03_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
