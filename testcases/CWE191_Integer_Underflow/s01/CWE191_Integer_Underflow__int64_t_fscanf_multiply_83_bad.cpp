/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_multiply_83_bad.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"
#include "CWE191_Integer_Underflow__int64_t_fscanf_multiply_83.h"

namespace CWE191_Integer_Underflow__int64_t_fscanf_multiply_83
{
CWE191_Integer_Underflow__int64_t_fscanf_multiply_83_bad::CWE191_Integer_Underflow__int64_t_fscanf_multiply_83_bad(int64_t dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%" SCNd64, &data);
}

CWE191_Integer_Underflow__int64_t_fscanf_multiply_83_bad::~CWE191_Integer_Underflow__int64_t_fscanf_multiply_83_bad()
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
        int64_t result = data * 2;
        printLongLongLine(result);
    }
}
}
