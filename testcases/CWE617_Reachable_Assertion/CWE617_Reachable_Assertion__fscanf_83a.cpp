/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_83a.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE617_Reachable_Assertion__fscanf_83.h"

namespace CWE617_Reachable_Assertion__fscanf_83
{


void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE617_Reachable_Assertion__fscanf_83_bad badObject(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE617_Reachable_Assertion__fscanf_83_goodG2B goodG2BObject(data);
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE617_Reachable_Assertion__fscanf_83; /* so that we can use good and bad easily */

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
