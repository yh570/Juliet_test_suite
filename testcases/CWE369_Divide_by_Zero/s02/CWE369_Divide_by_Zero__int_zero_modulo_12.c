/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_12.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


void CWE369_Divide_by_Zero__int_zero_modulo_12_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    else
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
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



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    else
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    if(globalReturnsTrueOrFalse())
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

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    else
    {
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
    }
    else
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
    }
}

void CWE369_Divide_by_Zero__int_zero_modulo_12_good()
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
    CWE369_Divide_by_Zero__int_zero_modulo_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_zero_modulo_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
