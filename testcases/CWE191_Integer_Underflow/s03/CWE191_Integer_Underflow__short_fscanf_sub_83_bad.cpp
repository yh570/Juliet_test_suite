/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_fscanf_sub_83_bad.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__short_fscanf_sub_83.h"

namespace CWE191_Integer_Underflow__short_fscanf_sub_83
{
CWE191_Integer_Underflow__short_fscanf_sub_83_bad::CWE191_Integer_Underflow__short_fscanf_sub_83_bad(short dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hd", &data);
}

CWE191_Integer_Underflow__short_fscanf_sub_83_bad::~CWE191_Integer_Underflow__short_fscanf_sub_83_bad()
{
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        short result = data - 1;
        printIntLine(result);
    }
}
}
