/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int64_t_22b.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-22b.tmpl.c
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
extern int CWE563_Unused_Variable__unused_init_variable_int64_t_22_badGlobal;

void CWE563_Unused_Variable__unused_init_variable_int64_t_22_badSink(int64_t data)
{
    if(CWE563_Unused_Variable__unused_init_variable_int64_t_22_badGlobal)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE563_Unused_Variable__unused_init_variable_int64_t_22_goodB2G1Global;
extern int CWE563_Unused_Variable__unused_init_variable_int64_t_22_goodB2G2Global;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE563_Unused_Variable__unused_init_variable_int64_t_22_goodB2G1Sink(int64_t data)
{
    if(CWE563_Unused_Variable__unused_init_variable_int64_t_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data */
        printLongLongLine(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE563_Unused_Variable__unused_init_variable_int64_t_22_goodB2G2Sink(int64_t data)
{
    if(CWE563_Unused_Variable__unused_init_variable_int64_t_22_goodB2G2Global)
    {
        /* FIX: Use data */
        printLongLongLine(data);
    }
}

