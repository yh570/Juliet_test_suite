/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_multiply_68a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

short CWE191_Integer_Underflow__short_min_multiply_68_badData;
short CWE191_Integer_Underflow__short_min_multiply_68_goodG2BData;
short CWE191_Integer_Underflow__short_min_multiply_68_goodB2GData;


/* bad function declaration */
void CWE191_Integer_Underflow__short_min_multiply_68b_badSink();

void CWE191_Integer_Underflow__short_min_multiply_68_bad()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
    CWE191_Integer_Underflow__short_min_multiply_68_badData = data;
    CWE191_Integer_Underflow__short_min_multiply_68b_badSink();
}



/* good function declarations */
void CWE191_Integer_Underflow__short_min_multiply_68b_goodG2BSink();
void CWE191_Integer_Underflow__short_min_multiply_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__short_min_multiply_68_goodG2BData = data;
    CWE191_Integer_Underflow__short_min_multiply_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = SHRT_MIN;
    CWE191_Integer_Underflow__short_min_multiply_68_goodB2GData = data;
    CWE191_Integer_Underflow__short_min_multiply_68b_goodB2GSink();
}

void CWE191_Integer_Underflow__short_min_multiply_68_good()
{
    goodG2B();
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE191_Integer_Underflow__short_min_multiply_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_min_multiply_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
