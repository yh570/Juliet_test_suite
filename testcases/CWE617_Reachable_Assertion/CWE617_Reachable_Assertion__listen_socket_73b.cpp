/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__listen_socket_73b.cpp
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <assert.h>

#define ASSERT_VALUE 5

using namespace std;

namespace CWE617_Reachable_Assertion__listen_socket_73
{


void badSink(list<int> dataList)
{
    /* copy data out of dataList */
    int data = dataList.back();
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<int> dataList)
{
    int data = dataList.back();
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}


} /* close namespace */
