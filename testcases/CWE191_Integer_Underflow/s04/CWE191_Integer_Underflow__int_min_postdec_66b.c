/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_postdec_66b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__int_min_postdec_66b_badSink(int dataArray[])
{
    /* copy data out of dataArray */
    int data = dataArray[2];
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        int result = data;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_min_postdec_66b_goodG2BSink(int dataArray[])
{
    int data = dataArray[2];
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        int result = data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_min_postdec_66b_goodB2GSink(int dataArray[])
{
    int data = dataArray[2];
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > INT_MIN)
    {
        data--;
        int result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

