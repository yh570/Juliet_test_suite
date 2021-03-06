/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fscanf_modulo_66b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE369_Divide_by_Zero__int_fscanf_modulo_66b_badSink(int dataArray[])
{
    /* copy data out of dataArray */
    int data = dataArray[2];
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_fscanf_modulo_66b_goodG2BSink(int dataArray[])
{
    int data = dataArray[2];
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_fscanf_modulo_66b_goodB2GSink(int dataArray[])
{
    int data = dataArray[2];
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

