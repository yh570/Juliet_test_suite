/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_06.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-06.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

/* The variable below is declared "const", so a tool should be able
 * to identify that reads of this will always give its initialized value. */
static const int STATIC_CONST_FIVE = 5;


void CWE617_Reachable_Assertion__rand_06_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}



/* goodG2B1() - use goodsource and badsink by changing the STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a value greater than the assert value */
        data = ASSERT_VALUE+1;
    }
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(STATIC_CONST_FIVE==5)
    {
        /* FIX: Use a value greater than the assert value */
        data = ASSERT_VALUE+1;
    }
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

void CWE617_Reachable_Assertion__rand_06_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE617_Reachable_Assertion__rand_06_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__rand_06_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
