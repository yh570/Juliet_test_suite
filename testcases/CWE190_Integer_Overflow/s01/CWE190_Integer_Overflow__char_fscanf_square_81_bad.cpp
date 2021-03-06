/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_square_81_bad.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__char_fscanf_square_81.h"

#include <math.h>

namespace CWE190_Integer_Overflow__char_fscanf_square_81
{

void CWE190_Integer_Overflow__char_fscanf_square_81_bad::action(char data) const
{
    {
        /* POTENTIAL FLAW: if (data*data) > CHAR_MAX, this will overflow */
        char result = data * data;
        printHexCharLine(result);
    }
}

}
