/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_sub_54d.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__short_min_sub_54e_badSink(short data);

void CWE191_Integer_Underflow__short_min_sub_54d_badSink(short data)
{
    CWE191_Integer_Underflow__short_min_sub_54e_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__short_min_sub_54e_goodG2BSink(short data);

void CWE191_Integer_Underflow__short_min_sub_54d_goodG2BSink(short data)
{
    CWE191_Integer_Underflow__short_min_sub_54e_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__short_min_sub_54e_goodB2GSink(short data);

void CWE191_Integer_Underflow__short_min_sub_54d_goodB2GSink(short data)
{
    CWE191_Integer_Underflow__short_min_sub_54e_goodB2GSink(data);
}

