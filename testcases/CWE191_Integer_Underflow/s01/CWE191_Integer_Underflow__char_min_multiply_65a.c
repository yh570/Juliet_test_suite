/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_min_multiply_65a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for char
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__char_min_multiply_65b_badSink(char data);

void CWE191_Integer_Underflow__char_min_multiply_65_bad()
{
    char data;
    /* define a function pointer */
    void (*funcPtr) (char) = CWE191_Integer_Underflow__char_min_multiply_65b_badSink;
    data = ' ';
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = CHAR_MIN;
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__char_min_multiply_65b_goodG2BSink(char data);

static void goodG2B()
{
    char data;
    void (*funcPtr) (char) = CWE191_Integer_Underflow__char_min_multiply_65b_goodG2BSink;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__char_min_multiply_65b_goodB2GSink(char data);

static void goodB2G()
{
    char data;
    void (*funcPtr) (char) = CWE191_Integer_Underflow__char_min_multiply_65b_goodB2GSink;
    data = ' ';
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = CHAR_MIN;
    funcPtr(data);
}

void CWE191_Integer_Underflow__char_min_multiply_65_good()
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
    CWE191_Integer_Underflow__char_min_multiply_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_min_multiply_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
