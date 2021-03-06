/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_rand_82_goodG2B.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE197_Numeric_Truncation_Error__short_rand_82.h"

namespace CWE197_Numeric_Truncation_Error__short_rand_82
{

void CWE197_Numeric_Truncation_Error__short_rand_82_goodG2B::action(short data)
{
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

}
