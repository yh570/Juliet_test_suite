/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_sub_61b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


short CWE191_Integer_Underflow__short_min_sub_61b_badSource(short data)
{
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
short CWE191_Integer_Underflow__short_min_sub_61b_goodG2BSource(short data)
{
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
short CWE191_Integer_Underflow__short_min_sub_61b_goodB2GSource(short data)
{
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
    return data;
}

