/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_42.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"


static int badSource(int count)
{
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    return count;
}

void CWE400_Resource_Exhaustion__rand_for_loop_42_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    count = badSource(count);
    {
        size_t i = 0;
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
static int goodG2BSource(int count)
{
    /* FIX: Use a relatively small number */
    count = 20;
    return count;
}

static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    count = goodG2BSource(count);
    {
        size_t i = 0;
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static int goodB2GSource(int count)
{
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    return count;
}

static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    count = goodB2GSource(count);
    {
        size_t i = 0;
        /* FIX: Validate count before using it as the for loop variant */
        if (count > 0 && count <= 20)
        {
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

void CWE400_Resource_Exhaustion__rand_for_loop_42_good()
{
    goodB2G();
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE400_Resource_Exhaustion__rand_for_loop_42_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__rand_for_loop_42_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
