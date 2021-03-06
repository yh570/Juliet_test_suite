/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fscanf_multiply_22a.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the sink function */
int CWE191_Integer_Underflow__int_fscanf_multiply_22_badGlobal = 0;

void CWE191_Integer_Underflow__int_fscanf_multiply_22_badSink(int data);

void CWE191_Integer_Underflow__int_fscanf_multiply_22_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE191_Integer_Underflow__int_fscanf_multiply_22_badGlobal = 1; /* true */
    CWE191_Integer_Underflow__int_fscanf_multiply_22_badSink(data);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G1Global = 0;
int CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G2Global = 0;
int CWE191_Integer_Underflow__int_fscanf_multiply_22_goodG2BGlobal = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G1Sink(int data);

static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G1Global = 0; /* false */
    CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G2Sink(int data);

static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G2Global = 1; /* true */
    CWE191_Integer_Underflow__int_fscanf_multiply_22_goodB2G2Sink(data);
}

/* goodG2B() - use goodsource and badsink */
void CWE191_Integer_Underflow__int_fscanf_multiply_22_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__int_fscanf_multiply_22_goodG2BGlobal = 1; /* true */
    CWE191_Integer_Underflow__int_fscanf_multiply_22_goodG2BSink(data);
}

void CWE191_Integer_Underflow__int_fscanf_multiply_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
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
    CWE191_Integer_Underflow__int_fscanf_multiply_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_fscanf_multiply_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
