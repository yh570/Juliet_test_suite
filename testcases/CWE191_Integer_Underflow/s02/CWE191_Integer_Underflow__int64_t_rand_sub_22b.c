/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_sub_22b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the sink function */
extern int CWE191_Integer_Underflow__int64_t_rand_sub_22_badGlobal;

void CWE191_Integer_Underflow__int64_t_rand_sub_22_badSink(int64_t data)
{
    if(CWE191_Integer_Underflow__int64_t_rand_sub_22_badGlobal)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            int64_t result = data - 1;
            printLongLongLine(result);
        }
    }
}



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE191_Integer_Underflow__int64_t_rand_sub_22_goodB2G1Global;
extern int CWE191_Integer_Underflow__int64_t_rand_sub_22_goodB2G2Global;
extern int CWE191_Integer_Underflow__int64_t_rand_sub_22_goodG2BGlobal;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE191_Integer_Underflow__int64_t_rand_sub_22_goodB2G1Sink(int64_t data)
{
    if(CWE191_Integer_Underflow__int64_t_rand_sub_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > LLONG_MIN)
        {
            int64_t result = data - 1;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform subtraction.");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE191_Integer_Underflow__int64_t_rand_sub_22_goodB2G2Sink(int64_t data)
{
    if(CWE191_Integer_Underflow__int64_t_rand_sub_22_goodB2G2Global)
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > LLONG_MIN)
        {
            int64_t result = data - 1;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform subtraction.");
        }
    }
}

/* goodG2B() - use goodsource and badsink */
void CWE191_Integer_Underflow__int64_t_rand_sub_22_goodG2BSink(int64_t data)
{
    if(CWE191_Integer_Underflow__int64_t_rand_sub_22_goodG2BGlobal)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            int64_t result = data - 1;
            printLongLongLine(result);
        }
    }
}

