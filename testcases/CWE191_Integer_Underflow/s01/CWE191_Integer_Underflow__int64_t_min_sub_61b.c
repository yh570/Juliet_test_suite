/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_min_sub_61b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for int64_t
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


int64_t CWE191_Integer_Underflow__int64_t_min_sub_61b_badSource(int64_t data)
{
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = LLONG_MIN;
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
int64_t CWE191_Integer_Underflow__int64_t_min_sub_61b_goodG2BSource(int64_t data)
{
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
int64_t CWE191_Integer_Underflow__int64_t_min_sub_61b_goodB2GSource(int64_t data)
{
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = LLONG_MIN;
    return data;
}

