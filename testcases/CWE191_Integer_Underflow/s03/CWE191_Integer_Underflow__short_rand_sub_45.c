/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_sub_45.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static short CWE191_Integer_Underflow__short_rand_sub_45_badData;
static short CWE191_Integer_Underflow__short_rand_sub_45_goodG2BData;
static short CWE191_Integer_Underflow__short_rand_sub_45_goodB2GData;


static void badSink()
{
    short data = CWE191_Integer_Underflow__short_rand_sub_45_badData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        short result = data - 1;
        printIntLine(result);
    }
}

void CWE191_Integer_Underflow__short_rand_sub_45_bad()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    CWE191_Integer_Underflow__short_rand_sub_45_badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    short data = CWE191_Integer_Underflow__short_rand_sub_45_goodG2BData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        short result = data - 1;
        printIntLine(result);
    }
}

static void goodG2B()
{
    short data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__short_rand_sub_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    short data = CWE191_Integer_Underflow__short_rand_sub_45_goodB2GData;
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

static void goodB2G()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    CWE191_Integer_Underflow__short_rand_sub_45_goodB2GData = data;
    goodB2GSink();
}

void CWE191_Integer_Underflow__short_rand_sub_45_good()
{
    goodG2B();
    goodB2G();
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
    CWE191_Integer_Underflow__short_rand_sub_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_rand_sub_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
