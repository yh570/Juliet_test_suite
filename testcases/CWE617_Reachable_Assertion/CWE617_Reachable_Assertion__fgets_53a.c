/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fgets_53a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-53a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


/* bad function declaration */
void CWE617_Reachable_Assertion__fgets_53b_badSink(int data);

void CWE617_Reachable_Assertion__fgets_53_bad()
{
    int data;
    /* Initialize data */
    data = -1;
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
    CWE617_Reachable_Assertion__fgets_53b_badSink(data);
}



/* good function declaration */
void CWE617_Reachable_Assertion__fgets_53b_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    CWE617_Reachable_Assertion__fgets_53b_goodG2BSink(data);
}

void CWE617_Reachable_Assertion__fgets_53_good()
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
    CWE617_Reachable_Assertion__fgets_53_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fgets_53_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
