/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_multiply_54a.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__int_min_multiply_54b_badSink(int data);

void CWE191_Integer_Underflow__int_min_multiply_54_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the minimum value for this type */
    data = INT_MIN;
    CWE191_Integer_Underflow__int_min_multiply_54b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_min_multiply_54b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__int_min_multiply_54b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_min_multiply_54b_goodB2GSink(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the minimum value for this type */
    data = INT_MIN;
    CWE191_Integer_Underflow__int_min_multiply_54b_goodB2GSink(data);
}

void CWE191_Integer_Underflow__int_min_multiply_54_good()
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
    CWE191_Integer_Underflow__int_min_multiply_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_min_multiply_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
