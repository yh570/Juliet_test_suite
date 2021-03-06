/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_64b.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


void CWE369_Divide_by_Zero__float_rand_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    float * dataPtr = (float *)dataVoidPtr;
    /* dereference dataPtr into data */
    float data = (*dataPtr);
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__float_rand_64b_goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    float * dataPtr = (float *)dataVoidPtr;
    /* dereference dataPtr into data */
    float data = (*dataPtr);
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__float_rand_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    float * dataPtr = (float *)dataVoidPtr;
    /* dereference dataPtr into data */
    float data = (*dataPtr);
    /* FIX: Check for value of or near zero before dividing */
    if(fabs(data) > 0.000001)
    {
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}

