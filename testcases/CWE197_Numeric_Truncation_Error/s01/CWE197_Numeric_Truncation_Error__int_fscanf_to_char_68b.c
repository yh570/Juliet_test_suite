/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_badData;
extern int CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b_badSink()
{
    int data = CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_badData;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b_goodG2BSink()
{
    int data = CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_goodG2BData;
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

