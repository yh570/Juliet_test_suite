/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_multiply_84_bad.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__short_min_multiply_84.h"

namespace CWE191_Integer_Underflow__short_min_multiply_84
{
CWE191_Integer_Underflow__short_min_multiply_84_bad::CWE191_Integer_Underflow__short_min_multiply_84_bad(short dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
}

CWE191_Integer_Underflow__short_min_multiply_84_bad::~CWE191_Integer_Underflow__short_min_multiply_84_bad()
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
        short result = data * 2;
        printIntLine(result);
    }
}
}
