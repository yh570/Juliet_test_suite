/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_wchar_t_10.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-10.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE563_Unused_Variable__unused_init_variable_wchar_t_10_bad()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    if(globalTrue)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodB2G1() - use badsource and goodsink by changing globalTrue to globalFalse */
static void goodB2G1()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data */
        printWcharLine(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    if(globalTrue)
    {
        /* FIX: Use data */
        printWcharLine(data);
    }
}

void CWE563_Unused_Variable__unused_init_variable_wchar_t_10_good()
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
    CWE563_Unused_Variable__unused_init_variable_wchar_t_10_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_init_variable_wchar_t_10_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
