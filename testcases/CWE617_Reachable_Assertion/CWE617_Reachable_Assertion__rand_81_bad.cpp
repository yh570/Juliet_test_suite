/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_81_bad.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE617_Reachable_Assertion__rand_81.h"

namespace CWE617_Reachable_Assertion__rand_81
{

void CWE617_Reachable_Assertion__rand_81_bad::action(int data) const
{
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

}
