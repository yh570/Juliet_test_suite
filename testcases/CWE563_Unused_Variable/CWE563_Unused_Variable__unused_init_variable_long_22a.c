/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_long_22a.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* The global variable below is used to drive control flow in the sink function */
int CWE563_Unused_Variable__unused_init_variable_long_22_badGlobal = 0;

void CWE563_Unused_Variable__unused_init_variable_long_22_badSink(long data);

void CWE563_Unused_Variable__unused_init_variable_long_22_bad()
{
    long data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5L;
    CWE563_Unused_Variable__unused_init_variable_long_22_badGlobal = 1; /* true */
    CWE563_Unused_Variable__unused_init_variable_long_22_badSink(data);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G1Global = 0;
int CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G2Global = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G1Sink(long data);

static void goodB2G1()
{
    long data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5L;
    CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G1Global = 0; /* false */
    CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G2Sink(long data);

static void goodB2G2()
{
    long data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5L;
    CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G2Global = 1; /* true */
    CWE563_Unused_Variable__unused_init_variable_long_22_goodB2G2Sink(data);
}

void CWE563_Unused_Variable__unused_init_variable_long_22_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE563_Unused_Variable__unused_init_variable_long_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_init_variable_long_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
