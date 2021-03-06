/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54a.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54b_badSink(int data);

void CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54b_badSink(data);
}



/* good function declaration */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54b_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54b_goodG2BSink(data);
}

void CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54_good()
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
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
