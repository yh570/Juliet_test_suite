/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_67a.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE197_Numeric_Truncation_Error__short_large_67_structType
{
    short structFirst;
} CWE197_Numeric_Truncation_Error__short_large_67_structType;


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__short_large_67b_badSink(CWE197_Numeric_Truncation_Error__short_large_67_structType myStruct);

void CWE197_Numeric_Truncation_Error__short_large_67_bad()
{
    short data;
    CWE197_Numeric_Truncation_Error__short_large_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a number larger than CHAR_MAX */
    data = CHAR_MAX + 1;
    myStruct.structFirst = data;
    CWE197_Numeric_Truncation_Error__short_large_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__short_large_67b_goodG2BSink(CWE197_Numeric_Truncation_Error__short_large_67_structType myStruct);

static void goodG2B()
{
    short data;
    CWE197_Numeric_Truncation_Error__short_large_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    myStruct.structFirst = data;
    CWE197_Numeric_Truncation_Error__short_large_67b_goodG2BSink(myStruct);
}

void CWE197_Numeric_Truncation_Error__short_large_67_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE197_Numeric_Truncation_Error__short_large_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_large_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
