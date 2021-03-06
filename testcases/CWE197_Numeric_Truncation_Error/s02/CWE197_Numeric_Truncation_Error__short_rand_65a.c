/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_rand_65a.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__short_rand_65b_badSink(short data);

void CWE197_Numeric_Truncation_Error__short_rand_65_bad()
{
    short data;
    /* define a function pointer */
    void (*funcPtr) (short) = CWE197_Numeric_Truncation_Error__short_rand_65b_badSink;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a random number */
    data = (short)RAND32();
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__short_rand_65b_goodG2BSink(short data);

static void goodG2B()
{
    short data;
    void (*funcPtr) (short) = CWE197_Numeric_Truncation_Error__short_rand_65b_goodG2BSink;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    funcPtr(data);
}

void CWE197_Numeric_Truncation_Error__short_rand_65_good()
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
    CWE197_Numeric_Truncation_Error__short_rand_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_rand_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
