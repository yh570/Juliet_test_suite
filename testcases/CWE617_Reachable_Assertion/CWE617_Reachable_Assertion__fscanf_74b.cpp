/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_74b.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <assert.h>

#define ASSERT_VALUE 5

using namespace std;

namespace CWE617_Reachable_Assertion__fscanf_74
{


void badSink(map<int, int> dataMap)
{
    /* copy data out of dataMap */
    int data = dataMap[2];
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, int> dataMap)
{
    int data = dataMap[2];
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}


} /* close namespace */
