/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_wchar_t_14.c
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE563_Unused_Variable__unused_uninit_variable_wchar_t_14_bad()
{
    wchar_t data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */
    if(globalFive==5)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodB2G1() - use badsource and goodsink by changing globalFive==5 to globalFive!=5 */
static void goodB2G1()
{
    wchar_t data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize then use data */
        data = L'W';
        printWcharLine(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    wchar_t data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */
    if(globalFive==5)
    {
        /* FIX: Initialize then use data */
        data = L'W';
        printWcharLine(data);
    }
}

void CWE563_Unused_Variable__unused_uninit_variable_wchar_t_14_good()
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
    CWE563_Unused_Variable__unused_uninit_variable_wchar_t_14_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_uninit_variable_wchar_t_14_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
