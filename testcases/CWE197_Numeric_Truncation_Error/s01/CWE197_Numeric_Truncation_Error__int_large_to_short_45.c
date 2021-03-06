/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_short_45.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int CWE197_Numeric_Truncation_Error__int_large_to_short_45_badData;
static int CWE197_Numeric_Truncation_Error__int_large_to_short_45_goodG2BData;


static void badSink()
{
    int data = CWE197_Numeric_Truncation_Error__int_large_to_short_45_badData;
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}

void CWE197_Numeric_Truncation_Error__int_large_to_short_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a number larger than SHRT_MAX */
    data = SHRT_MAX + 5;
    CWE197_Numeric_Truncation_Error__int_large_to_short_45_badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int data = CWE197_Numeric_Truncation_Error__int_large_to_short_45_goodG2BData;
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    CWE197_Numeric_Truncation_Error__int_large_to_short_45_goodG2BData = data;
    goodG2BSink();
}

void CWE197_Numeric_Truncation_Error__int_large_to_short_45_good()
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
    CWE197_Numeric_Truncation_Error__int_large_to_short_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_large_to_short_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
