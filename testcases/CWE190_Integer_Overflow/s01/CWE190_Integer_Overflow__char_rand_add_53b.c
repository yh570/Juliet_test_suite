/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_add_53b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE190_Integer_Overflow__char_rand_add_53c_badSink(char data);

void CWE190_Integer_Overflow__char_rand_add_53b_badSink(char data)
{
    CWE190_Integer_Overflow__char_rand_add_53c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_add_53c_goodG2BSink(char data);

void CWE190_Integer_Overflow__char_rand_add_53b_goodG2BSink(char data)
{
    CWE190_Integer_Overflow__char_rand_add_53c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_add_53c_goodB2GSink(char data);

void CWE190_Integer_Overflow__char_rand_add_53b_goodB2GSink(char data)
{
    CWE190_Integer_Overflow__char_rand_add_53c_goodB2GSink(data);
}

