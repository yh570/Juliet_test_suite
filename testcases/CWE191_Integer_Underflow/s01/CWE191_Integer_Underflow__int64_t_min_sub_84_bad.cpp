/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_min_sub_84_bad.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for int64_t
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__int64_t_min_sub_84.h"

namespace CWE191_Integer_Underflow__int64_t_min_sub_84
{
CWE191_Integer_Underflow__int64_t_min_sub_84_bad::CWE191_Integer_Underflow__int64_t_min_sub_84_bad(int64_t dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = LLONG_MIN;
}

CWE191_Integer_Underflow__int64_t_min_sub_84_bad::~CWE191_Integer_Underflow__int64_t_min_sub_84_bad()
{
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        int64_t result = data - 1;
        printLongLongLine(result);
    }
}
}
