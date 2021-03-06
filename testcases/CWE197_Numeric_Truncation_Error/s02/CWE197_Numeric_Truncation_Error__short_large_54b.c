/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_54b.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__short_large_54c_badSink(short data);

void CWE197_Numeric_Truncation_Error__short_large_54b_badSink(short data)
{
    CWE197_Numeric_Truncation_Error__short_large_54c_badSink(data);
}



/* good function declaration */
void CWE197_Numeric_Truncation_Error__short_large_54c_goodG2BSink(short data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__short_large_54b_goodG2BSink(short data)
{
    CWE197_Numeric_Truncation_Error__short_large_54c_goodG2BSink(data);
}

