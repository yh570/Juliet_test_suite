/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_max_square_82_goodB2G.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int64_t
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int64_t_max_square_82.h"

#include <math.h>
#include <inttypes.h>

namespace CWE190_Integer_Overflow__int64_t_max_square_82
{

void CWE190_Integer_Overflow__int64_t_max_square_82_goodB2G::action(int64_t data)
{
    /* FIX: Add a check to prevent an overflow from occurring */
    if (imaxabs((intmax_t)data) <= sqrtl(LLONG_MAX))
    {
        int64_t result = data * data;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

}
