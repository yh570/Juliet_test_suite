/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_sleep_13.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-13.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif


void CWE400_Resource_Exhaustion__rand_sleep_13_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Set count to a random value */
        count = RAND32();
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodB2G1()
{
    int count;
    /* Initialize count */
    count = -1;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Set count to a random value */
        count = RAND32();
    }
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Validate count before using it as a parameter in the sleep function */
        if (count > 0 && count <= 2000)
        {
            SLEEP(count);
            printLine("Sleep time OK");
        }
        else
        {
            printLine("Sleep time too long");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int count;
    /* Initialize count */
    count = -1;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Set count to a random value */
        count = RAND32();
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FIX: Validate count before using it as a parameter in the sleep function */
        if (count > 0 && count <= 2000)
        {
            SLEEP(count);
            printLine("Sleep time OK");
        }
        else
        {
            printLine("Sleep time too long");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodG2B1()
{
    int count;
    /* Initialize count */
    count = -1;
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int count;
    /* Initialize count */
    count = -1;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}

void CWE400_Resource_Exhaustion__rand_sleep_13_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE400_Resource_Exhaustion__rand_sleep_13_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__rand_sleep_13_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
