/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_fscanf_multiply_84_goodB2G.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__char_fscanf_multiply_84.h"

namespace CWE191_Integer_Underflow__char_fscanf_multiply_84
{
CWE191_Integer_Underflow__char_fscanf_multiply_84_goodB2G::CWE191_Integer_Underflow__char_fscanf_multiply_84_goodB2G(char dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
}

CWE191_Integer_Underflow__char_fscanf_multiply_84_goodB2G::~CWE191_Integer_Underflow__char_fscanf_multiply_84_goodB2G()
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > (CHAR_MIN/2))
        {
            char result = data * 2;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too small to perform multiplication.");
        }
    }
}
}
