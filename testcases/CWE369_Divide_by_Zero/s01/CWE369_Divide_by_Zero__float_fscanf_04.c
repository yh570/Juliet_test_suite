/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_fscanf_04.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <math.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */


void CWE369_Divide_by_Zero__float_fscanf_04_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
        fscanf (stdin, "%f", &data);
    }
    if(STATIC_CONST_TRUE)
    {
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodB2G1()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
        fscanf (stdin, "%f", &data);
    }
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Check for value of or near zero before dividing */
        if(fabs(data) > 0.000001)
        {
            int result = (int)(100.0 / data);
            printIntLine(result);
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
    float data;
    /* Initialize data */
    data = 0.0F;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
        fscanf (stdin, "%f", &data);
    }
    if(STATIC_CONST_TRUE)
    {
        /* FIX: Check for value of or near zero before dividing */
        if(fabs(data) > 0.000001)
        {
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
        else
        {
            printLine("This would result in a divide by zero");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodG2B1()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a hardcoded number that won't a divide by zero */
        data = 2.0F;
    }
    if(STATIC_CONST_TRUE)
    {
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    if(STATIC_CONST_TRUE)
    {
        /* FIX: Use a hardcoded number that won't a divide by zero */
        data = 2.0F;
    }
    if(STATIC_CONST_TRUE)
    {
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
    }
}

void CWE369_Divide_by_Zero__float_fscanf_04_good()
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
    CWE369_Divide_by_Zero__float_fscanf_04_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__float_fscanf_04_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
