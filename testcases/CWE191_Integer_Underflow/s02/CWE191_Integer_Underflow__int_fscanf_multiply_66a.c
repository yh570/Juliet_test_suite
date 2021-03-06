/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fscanf_multiply_66a.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE191_Integer_Underflow__int_fscanf_multiply_66b_badSink(int dataArray[]);

void CWE191_Integer_Underflow__int_fscanf_multiply_66_bad()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    /* put data in array */
    dataArray[2] = data;
    CWE191_Integer_Underflow__int_fscanf_multiply_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_fscanf_multiply_66b_goodG2BSink(int dataArray[]);

static void goodG2B()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
    data = -2;
    dataArray[2] = data;
    CWE191_Integer_Underflow__int_fscanf_multiply_66b_goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_fscanf_multiply_66b_goodB2GSink(int dataArray[]);

static void goodB2G()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    dataArray[2] = data;
    CWE191_Integer_Underflow__int_fscanf_multiply_66b_goodB2GSink(dataArray);
}

void CWE191_Integer_Underflow__int_fscanf_multiply_66_good()
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
    CWE191_Integer_Underflow__int_fscanf_multiply_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_fscanf_multiply_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
