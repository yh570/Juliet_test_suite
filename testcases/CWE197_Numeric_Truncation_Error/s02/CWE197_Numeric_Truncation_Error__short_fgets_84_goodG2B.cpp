/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_fgets_84_goodG2B.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE197_Numeric_Truncation_Error__short_fgets_84.h"

namespace CWE197_Numeric_Truncation_Error__short_fgets_84
{
CWE197_Numeric_Truncation_Error__short_fgets_84_goodG2B::CWE197_Numeric_Truncation_Error__short_fgets_84_goodG2B(short dataCopy)
{
    data = dataCopy;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
}

CWE197_Numeric_Truncation_Error__short_fgets_84_goodG2B::~CWE197_Numeric_Truncation_Error__short_fgets_84_goodG2B()
{
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}
}
