/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_multiply_41.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"


static void badSink(short data)
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
        short result = data * 2;
        printIntLine(result);
    }
}

void CWE191_Integer_Underflow__short_min_multiply_41_bad()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
    badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2BSink(short data)
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
        short result = data * 2;
        printIntLine(result);
    }
}

static void goodG2B()
{
    short data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2GSink(short data)
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > (SHRT_MIN/2))
        {
            short result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too small to perform multiplication.");
        }
    }
}

static void goodB2G()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
    goodB2GSink(data);
}

void CWE191_Integer_Underflow__short_min_multiply_41_good()
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
    CWE191_Integer_Underflow__short_min_multiply_41_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_min_multiply_41_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
