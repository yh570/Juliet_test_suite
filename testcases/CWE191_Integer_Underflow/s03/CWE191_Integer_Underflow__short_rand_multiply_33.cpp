/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_multiply_33.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE191_Integer_Underflow__short_rand_multiply_33
{


void bad()
{
    short data;
    short &dataRef = data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    {
        short data = dataRef;
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
            short result = data * 2;
            printIntLine(result);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    short &dataRef = data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    {
        short data = dataRef;
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
            short result = data * 2;
            printIntLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    short data;
    short &dataRef = data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    {
        short data = dataRef;
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

using namespace CWE191_Integer_Underflow__short_rand_multiply_33; /* so that we can use good and bad easily */

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
