/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_max_preinc_52b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int64_t
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE190_Integer_Overflow__int64_t_max_preinc_52c_badSink(int64_t data);

void CWE190_Integer_Overflow__int64_t_max_preinc_52b_badSink(int64_t data)
{
    CWE190_Integer_Overflow__int64_t_max_preinc_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int64_t_max_preinc_52c_goodG2BSink(int64_t data);

void CWE190_Integer_Overflow__int64_t_max_preinc_52b_goodG2BSink(int64_t data)
{
    CWE190_Integer_Overflow__int64_t_max_preinc_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int64_t_max_preinc_52c_goodB2GSink(int64_t data);

void CWE190_Integer_Overflow__int64_t_max_preinc_52b_goodB2GSink(int64_t data)
{
    CWE190_Integer_Overflow__int64_t_max_preinc_52c_goodB2GSink(data);
}

