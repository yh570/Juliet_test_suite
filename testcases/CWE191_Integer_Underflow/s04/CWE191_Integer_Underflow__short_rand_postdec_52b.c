/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_postdec_52b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__short_rand_postdec_52c_badSink(short data);

void CWE191_Integer_Underflow__short_rand_postdec_52b_badSink(short data)
{
    CWE191_Integer_Underflow__short_rand_postdec_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__short_rand_postdec_52c_goodG2BSink(short data);

void CWE191_Integer_Underflow__short_rand_postdec_52b_goodG2BSink(short data)
{
    CWE191_Integer_Underflow__short_rand_postdec_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__short_rand_postdec_52c_goodB2GSink(short data);

void CWE191_Integer_Underflow__short_rand_postdec_52b_goodB2GSink(short data)
{
    CWE191_Integer_Underflow__short_rand_postdec_52c_goodB2GSink(data);
}

