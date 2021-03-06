/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_22a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the sink function */
int CWE400_Resource_Exhaustion__fscanf_for_loop_22_badGlobal = 0;

void CWE400_Resource_Exhaustion__fscanf_for_loop_22_badSink(int count);

void CWE400_Resource_Exhaustion__fscanf_for_loop_22_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_badGlobal = 1; /* true */
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_badSink(count);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G1Global = 0;
int CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G2Global = 0;
int CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodG2BGlobal = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G1Sink(int count);

static void goodB2G1()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G1Global = 0; /* false */
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G1Sink(count);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G2Sink(int count);

static void goodB2G2()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G2Global = 1; /* true */
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodB2G2Sink(count);
}

/* goodG2B() - use goodsource and badsink */
void CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodG2BSink(int count);

static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodG2BGlobal = 1; /* true */
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_goodG2BSink(count);
}

void CWE400_Resource_Exhaustion__fscanf_for_loop_22_good()
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
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
