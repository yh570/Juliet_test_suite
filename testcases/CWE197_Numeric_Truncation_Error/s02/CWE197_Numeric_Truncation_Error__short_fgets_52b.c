/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_fgets_52b.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__short_fgets_52c_badSink(short data);

void CWE197_Numeric_Truncation_Error__short_fgets_52b_badSink(short data)
{
    CWE197_Numeric_Truncation_Error__short_fgets_52c_badSink(data);
}



/* good function declaration */
void CWE197_Numeric_Truncation_Error__short_fgets_52c_goodG2BSink(short data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__short_fgets_52b_goodG2BSink(short data)
{
    CWE197_Numeric_Truncation_Error__short_fgets_52c_goodG2BSink(data);
}

