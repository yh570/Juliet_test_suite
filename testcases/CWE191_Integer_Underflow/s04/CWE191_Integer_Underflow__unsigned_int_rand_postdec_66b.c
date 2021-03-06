/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_rand_postdec_66b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE191_Integer_Underflow__unsigned_int_rand_postdec_66b_badSink(unsigned int dataArray[])
{
    /* copy data out of dataArray */
    unsigned int data = dataArray[2];
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__unsigned_int_rand_postdec_66b_goodG2BSink(unsigned int dataArray[])
{
    unsigned int data = dataArray[2];
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__unsigned_int_rand_postdec_66b_goodB2GSink(unsigned int dataArray[])
{
    unsigned int data = dataArray[2];
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > 0)
    {
        data--;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

