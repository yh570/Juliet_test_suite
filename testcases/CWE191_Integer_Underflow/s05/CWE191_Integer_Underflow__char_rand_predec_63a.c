/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_rand_predec_63a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__char_rand_predec_63b_badSink(char * dataPtr);

void CWE191_Integer_Underflow__char_rand_predec_63_bad()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    CWE191_Integer_Underflow__char_rand_predec_63b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__char_rand_predec_63b_goodG2BSink(char * data);

static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__char_rand_predec_63b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__char_rand_predec_63b_goodB2GSink(char * data);

static void goodB2G()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    CWE191_Integer_Underflow__char_rand_predec_63b_goodB2GSink(&data);
}

void CWE191_Integer_Underflow__char_rand_predec_63_good()
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
    CWE191_Integer_Underflow__char_rand_predec_63_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_rand_predec_63_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
