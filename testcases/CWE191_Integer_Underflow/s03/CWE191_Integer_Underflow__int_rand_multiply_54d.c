/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_rand_multiply_54d.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__int_rand_multiply_54e_badSink(int data);

void CWE191_Integer_Underflow__int_rand_multiply_54d_badSink(int data)
{
    CWE191_Integer_Underflow__int_rand_multiply_54e_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_rand_multiply_54e_goodG2BSink(int data);

void CWE191_Integer_Underflow__int_rand_multiply_54d_goodG2BSink(int data)
{
    CWE191_Integer_Underflow__int_rand_multiply_54e_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_rand_multiply_54e_goodB2GSink(int data);

void CWE191_Integer_Underflow__int_rand_multiply_54d_goodB2GSink(int data)
{
    CWE191_Integer_Underflow__int_rand_multiply_54e_goodB2GSink(data);
}

