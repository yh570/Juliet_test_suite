/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_multiply_52b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__int64_t_fscanf_multiply_52c_badSink(int64_t data);

void CWE191_Integer_Underflow__int64_t_fscanf_multiply_52b_badSink(int64_t data)
{
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int64_t_fscanf_multiply_52c_goodG2BSink(int64_t data);

void CWE191_Integer_Underflow__int64_t_fscanf_multiply_52b_goodG2BSink(int64_t data)
{
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int64_t_fscanf_multiply_52c_goodB2GSink(int64_t data);

void CWE191_Integer_Underflow__int64_t_fscanf_multiply_52b_goodB2GSink(int64_t data)
{
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_52c_goodB2GSink(data);
}

