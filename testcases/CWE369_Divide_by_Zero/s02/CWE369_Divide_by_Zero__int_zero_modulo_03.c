/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_03.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"


void CWE369_Divide_by_Zero__int_zero_modulo_03_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: test for a zero denominator */
        if( data != 0 )
        {
            printIntLine(100 % data);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    if(5==5)
    {
        /* FIX: test for a zero denominator */
        if( data != 0 )
        {
            printIntLine(100 % data);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(5==5)
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
    }
}

void CWE369_Divide_by_Zero__int_zero_modulo_03_good()
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
    CWE369_Divide_by_Zero__int_zero_modulo_03_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_zero_modulo_03_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
