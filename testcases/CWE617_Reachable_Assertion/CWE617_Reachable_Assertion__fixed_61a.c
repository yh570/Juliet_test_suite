/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_61a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5


/* bad function declaration */
int CWE617_Reachable_Assertion__fixed_61b_badSource(int data);

void CWE617_Reachable_Assertion__fixed_61_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE617_Reachable_Assertion__fixed_61b_badSource(data);
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}



/* goodG2B uses the GoodSource with the BadSink */
int CWE617_Reachable_Assertion__fixed_61b_goodG2BSource(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE617_Reachable_Assertion__fixed_61b_goodG2BSource(data);
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

void CWE617_Reachable_Assertion__fixed_61_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE617_Reachable_Assertion__fixed_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fixed_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
