/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_rand_multiply_43.cpp
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE191_Integer_Underflow__int_rand_multiply_43
{


static void badSource(int &data)
{
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
}

void bad()
{
    int data;
    /* Initialize data */
    data = 0;
    badSource(data);
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
        int result = data * 2;
        printIntLine(result);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSource(int &data)
{
    /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
    data = -2;
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    goodG2BSource(data);
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < INT_MIN, this will underflow */
        int result = data * 2;
        printIntLine(result);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(int &data)
{
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    goodB2GSource(data);
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

void good()
{
    goodG2B();
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE191_Integer_Underflow__int_rand_multiply_43; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
