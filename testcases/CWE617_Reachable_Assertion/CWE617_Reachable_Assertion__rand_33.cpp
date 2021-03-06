/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_33.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

namespace CWE617_Reachable_Assertion__rand_33
{


void bad()
{
    int data;
    int &dataRef = data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    {
        int data = dataRef;
        /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
        assert(data > ASSERT_VALUE);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    int &dataRef = data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    {
        int data = dataRef;
        /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
        assert(data > ASSERT_VALUE);
    }
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

using namespace CWE617_Reachable_Assertion__rand_33; /* so that we can use good and bad easily */

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
