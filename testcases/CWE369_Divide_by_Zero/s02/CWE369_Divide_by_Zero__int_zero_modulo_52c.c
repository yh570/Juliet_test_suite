/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_52c.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


void CWE369_Divide_by_Zero__int_zero_modulo_52c_badSink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_zero_modulo_52c_goodG2BSink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_zero_modulo_52c_goodB2GSink(int data)
{
    /* FIX: test for a zero denominator */
    if( data != 0 )
    {
        printIntLine(100 % data);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}

