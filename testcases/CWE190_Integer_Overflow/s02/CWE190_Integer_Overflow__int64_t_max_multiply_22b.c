/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_max_multiply_22b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int64_t
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the sink function */
extern int CWE190_Integer_Overflow__int64_t_max_multiply_22_badGlobal;

void CWE190_Integer_Overflow__int64_t_max_multiply_22_badSink(int64_t data)
{
    if(CWE190_Integer_Overflow__int64_t_max_multiply_22_badGlobal)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > LLONG_MAX, this will overflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE190_Integer_Overflow__int64_t_max_multiply_22_goodB2G1Global;
extern int CWE190_Integer_Overflow__int64_t_max_multiply_22_goodB2G2Global;
extern int CWE190_Integer_Overflow__int64_t_max_multiply_22_goodG2BGlobal;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE190_Integer_Overflow__int64_t_max_multiply_22_goodB2G1Sink(int64_t data)
{
    if(CWE190_Integer_Overflow__int64_t_max_multiply_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < (LLONG_MAX/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE190_Integer_Overflow__int64_t_max_multiply_22_goodB2G2Sink(int64_t data)
{
    if(CWE190_Integer_Overflow__int64_t_max_multiply_22_goodB2G2Global)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < (LLONG_MAX/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B() - use goodsource and badsink */
void CWE190_Integer_Overflow__int64_t_max_multiply_22_goodG2BSink(int64_t data)
{
    if(CWE190_Integer_Overflow__int64_t_max_multiply_22_goodG2BGlobal)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > LLONG_MAX, this will overflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}

