/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_sub_54c.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__int_min_sub_54d_badSink(int data);

void CWE191_Integer_Underflow__int_min_sub_54c_badSink(int data)
{
    CWE191_Integer_Underflow__int_min_sub_54d_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_min_sub_54d_goodG2BSink(int data);

void CWE191_Integer_Underflow__int_min_sub_54c_goodG2BSink(int data)
{
    CWE191_Integer_Underflow__int_min_sub_54d_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_min_sub_54d_goodB2GSink(int data);

void CWE191_Integer_Underflow__int_min_sub_54c_goodB2GSink(int data)
{
    CWE191_Integer_Underflow__int_min_sub_54d_goodB2GSink(data);
}

