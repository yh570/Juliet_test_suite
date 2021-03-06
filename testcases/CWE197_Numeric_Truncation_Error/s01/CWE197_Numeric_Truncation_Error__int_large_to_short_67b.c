/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_short_67b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE197_Numeric_Truncation_Error__int_large_to_short_67_structType
{
    int structFirst;
} CWE197_Numeric_Truncation_Error__int_large_to_short_67_structType;


void CWE197_Numeric_Truncation_Error__int_large_to_short_67b_badSink(CWE197_Numeric_Truncation_Error__int_large_to_short_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_large_to_short_67b_goodG2BSink(CWE197_Numeric_Truncation_Error__int_large_to_short_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}

