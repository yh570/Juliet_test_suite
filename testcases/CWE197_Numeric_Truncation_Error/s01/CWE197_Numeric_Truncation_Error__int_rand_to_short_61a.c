/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_rand_to_short_61a.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
int CWE197_Numeric_Truncation_Error__int_rand_to_short_61b_badSource(int data);

void CWE197_Numeric_Truncation_Error__int_rand_to_short_61_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE197_Numeric_Truncation_Error__int_rand_to_short_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
int CWE197_Numeric_Truncation_Error__int_rand_to_short_61b_goodG2BSource(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE197_Numeric_Truncation_Error__int_rand_to_short_61b_goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}

void CWE197_Numeric_Truncation_Error__int_rand_to_short_61_good()
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
    CWE197_Numeric_Truncation_Error__int_rand_to_short_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_rand_to_short_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
