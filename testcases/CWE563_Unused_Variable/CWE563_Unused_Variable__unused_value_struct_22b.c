/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_22b.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* The global variable below is used to drive control flow in the sink function */
extern int CWE563_Unused_Variable__unused_value_struct_22_badGlobal;

void CWE563_Unused_Variable__unused_value_struct_22_badSink(twoIntsStruct data)
{
    if(CWE563_Unused_Variable__unused_value_struct_22_badGlobal)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE563_Unused_Variable__unused_value_struct_22_goodB2G1Global;
extern int CWE563_Unused_Variable__unused_value_struct_22_goodB2G2Global;
extern int CWE563_Unused_Variable__unused_value_struct_22_goodG2BGlobal;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE563_Unused_Variable__unused_value_struct_22_goodB2G1Sink(twoIntsStruct data)
{
    if(CWE563_Unused_Variable__unused_value_struct_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE563_Unused_Variable__unused_value_struct_22_goodB2G2Sink(twoIntsStruct data)
{
    if(CWE563_Unused_Variable__unused_value_struct_22_goodB2G2Global)
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodG2B() - use goodsource and badsink */
void CWE563_Unused_Variable__unused_value_struct_22_goodG2BSink(twoIntsStruct data)
{
    if(CWE563_Unused_Variable__unused_value_struct_22_goodG2BGlobal)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

