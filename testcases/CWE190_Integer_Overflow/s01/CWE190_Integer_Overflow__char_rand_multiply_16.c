/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_16.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__char_rand_multiply_16_bad()
{
    char data;
    data = ' ';
    while(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
        break;
    }
    while(1)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
        break;
    }
}



/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
static void goodB2G()
{
    char data;
    data = ' ';
    while(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
        break;
    }
    while(1)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < (CHAR_MAX/2))
            {
                char result = data * 2;
                printHexCharLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
static void goodG2B()
{
    char data;
    data = ' ';
    while(1)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
        break;
    }
    while(1)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
            char result = data * 2;
            printHexCharLine(result);
        }
        break;
    }
}

void CWE190_Integer_Overflow__char_rand_multiply_16_good()
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
    CWE190_Integer_Overflow__char_rand_multiply_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_multiply_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
