/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_square_53b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


/* bad function declaration */
void CWE190_Integer_Overflow__int_max_square_53c_badSink(int data);

void CWE190_Integer_Overflow__int_max_square_53b_badSink(int data)
{
    CWE190_Integer_Overflow__int_max_square_53c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_max_square_53c_goodG2BSink(int data);

void CWE190_Integer_Overflow__int_max_square_53b_goodG2BSink(int data)
{
    CWE190_Integer_Overflow__int_max_square_53c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_max_square_53c_goodB2GSink(int data);

void CWE190_Integer_Overflow__int_max_square_53b_goodB2GSink(int data)
{
    CWE190_Integer_Overflow__int_max_square_53c_goodB2GSink(data);
}

