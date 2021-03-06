/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_63b.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE197_Numeric_Truncation_Error__short_large_63b_badSink(short * dataPtr)
{
    short data = *dataPtr;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__short_large_63b_goodG2BSink(short * dataPtr)
{
    short data = *dataPtr;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

