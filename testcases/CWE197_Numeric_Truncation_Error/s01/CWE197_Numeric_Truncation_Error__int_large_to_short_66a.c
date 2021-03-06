/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_short_66a.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_large_to_short_66b_badSink(int dataArray[]);

void CWE197_Numeric_Truncation_Error__int_large_to_short_66_bad()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* FLAW: Use a number larger than SHRT_MAX */
    data = SHRT_MAX + 5;
    /* put data in array */
    dataArray[2] = data;
    CWE197_Numeric_Truncation_Error__int_large_to_short_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_large_to_short_66b_goodG2BSink(int dataArray[]);

static void goodG2B()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    dataArray[2] = data;
    CWE197_Numeric_Truncation_Error__int_large_to_short_66b_goodG2BSink(dataArray);
}

void CWE197_Numeric_Truncation_Error__int_large_to_short_66_good()
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
    CWE197_Numeric_Truncation_Error__int_large_to_short_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_large_to_short_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
