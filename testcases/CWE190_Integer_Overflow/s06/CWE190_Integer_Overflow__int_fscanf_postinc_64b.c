/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_postinc_64b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__int_fscanf_postinc_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * dataPtr = (int *)dataVoidPtr;
    /* dereference dataPtr into data */
    int data = (*dataPtr);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        int result = data;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_fscanf_postinc_64b_goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * dataPtr = (int *)dataVoidPtr;
    /* dereference dataPtr into data */
    int data = (*dataPtr);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        int result = data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_fscanf_postinc_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * dataPtr = (int *)dataVoidPtr;
    /* dereference dataPtr into data */
    int data = (*dataPtr);
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < INT_MAX)
    {
        data++;
        int result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

