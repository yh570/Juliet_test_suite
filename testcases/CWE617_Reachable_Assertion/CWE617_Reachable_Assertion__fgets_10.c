/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fgets_10.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-10.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


void CWE617_Reachable_Assertion__fgets_10_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalTrue)
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Read data from the console using fgets() */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Convert to int */
                data = atoi(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
        }
    }
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}



/* goodG2B1() - use goodsource and badsink by changing the globalTrue to globalFalse */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalFalse)
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
    if(globalTrue)
    {
        /* FIX: Use a value greater than the assert value */
        data = ASSERT_VALUE+1;
    }
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
}

void CWE617_Reachable_Assertion__fgets_10_good()
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
    CWE617_Reachable_Assertion__fgets_10_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fgets_10_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
