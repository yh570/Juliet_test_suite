/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_add_83_bad.cpp
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int_max_add_83.h"

namespace CWE190_Integer_Overflow__int_max_add_83
{
CWE190_Integer_Overflow__int_max_add_83_bad::CWE190_Integer_Overflow__int_max_add_83_bad(int dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
}

CWE190_Integer_Overflow__int_max_add_83_bad::~CWE190_Integer_Overflow__int_max_add_83_bad()
{
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int result = data + 1;
        printIntLine(result);
    }
}
}
