/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_postinc_18.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__short_max_postinc_18_bad()
{
    short data;
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = SHRT_MAX;
    goto sink;
sink:
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        short result = data;
        printIntLine(result);
    }
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    short data;
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = SHRT_MAX;
    goto sink;
sink:
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < SHRT_MAX)
    {
        data++;
        short result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    short data;
    data = 0;
    goto source;
source:
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    goto sink;
sink:
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        short result = data;
        printIntLine(result);
    }
}

void CWE190_Integer_Overflow__short_max_postinc_18_good()
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
    CWE190_Integer_Overflow__short_max_postinc_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__short_max_postinc_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
