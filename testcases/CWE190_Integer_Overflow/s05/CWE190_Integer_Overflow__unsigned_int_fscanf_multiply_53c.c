/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53c.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53d_badSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53c_badSink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53d_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53d_goodG2BSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53c_goodG2BSink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53d_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53d_goodB2GSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53c_goodB2GSink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_fscanf_multiply_53d_goodB2GSink(data);
}

