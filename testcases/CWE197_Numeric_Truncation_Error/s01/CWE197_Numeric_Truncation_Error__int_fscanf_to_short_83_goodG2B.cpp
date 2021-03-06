/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83_goodG2B.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83.h"

namespace CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83
{
CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83_goodG2B::CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83_goodG2B(int dataCopy)
{
    data = dataCopy;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
}

CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83_goodG2B::~CWE197_Numeric_Truncation_Error__int_fscanf_to_short_83_goodG2B()
{
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}
}
