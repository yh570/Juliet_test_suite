/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_67b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

typedef struct _CWE617_Reachable_Assertion__rand_67_structType
{
    int structFirst;
} CWE617_Reachable_Assertion__rand_67_structType;


void CWE617_Reachable_Assertion__rand_67b_badSink(CWE617_Reachable_Assertion__rand_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__rand_67b_goodG2BSink(CWE617_Reachable_Assertion__rand_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

