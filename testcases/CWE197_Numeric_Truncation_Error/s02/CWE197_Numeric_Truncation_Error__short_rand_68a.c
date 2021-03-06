/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_rand_68a.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

short CWE197_Numeric_Truncation_Error__short_rand_68_badData;
short CWE197_Numeric_Truncation_Error__short_rand_68_goodG2BData;


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__short_rand_68b_badSink();

void CWE197_Numeric_Truncation_Error__short_rand_68_bad()
{
    short data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a random number */
    data = (short)RAND32();
    CWE197_Numeric_Truncation_Error__short_rand_68_badData = data;
    CWE197_Numeric_Truncation_Error__short_rand_68b_badSink();
}



/* good function declarations */
void CWE197_Numeric_Truncation_Error__short_rand_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    CWE197_Numeric_Truncation_Error__short_rand_68_goodG2BData = data;
    CWE197_Numeric_Truncation_Error__short_rand_68b_goodG2BSink();
}

void CWE197_Numeric_Truncation_Error__short_rand_68_good()
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
    CWE197_Numeric_Truncation_Error__short_rand_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_rand_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
