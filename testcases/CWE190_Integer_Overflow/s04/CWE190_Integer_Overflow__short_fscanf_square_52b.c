/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_fscanf_square_52b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


/* bad function declaration */
void CWE190_Integer_Overflow__short_fscanf_square_52c_badSink(short data);

void CWE190_Integer_Overflow__short_fscanf_square_52b_badSink(short data)
{
    CWE190_Integer_Overflow__short_fscanf_square_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__short_fscanf_square_52c_goodG2BSink(short data);

void CWE190_Integer_Overflow__short_fscanf_square_52b_goodG2BSink(short data)
{
    CWE190_Integer_Overflow__short_fscanf_square_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__short_fscanf_square_52c_goodB2GSink(short data);

void CWE190_Integer_Overflow__short_fscanf_square_52b_goodB2GSink(short data)
{
    CWE190_Integer_Overflow__short_fscanf_square_52c_goodB2GSink(data);
}

