/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_postinc_64b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__unsigned_int_max_postinc_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    unsigned int * dataPtr = (unsigned int *)dataVoidPtr;
    /* dereference dataPtr into data */
    unsigned int data = (*dataPtr);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_max_postinc_64b_goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    unsigned int * dataPtr = (unsigned int *)dataVoidPtr;
    /* dereference dataPtr into data */
    unsigned int data = (*dataPtr);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_max_postinc_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    unsigned int * dataPtr = (unsigned int *)dataVoidPtr;
    /* dereference dataPtr into data */
    unsigned int data = (*dataPtr);
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < UINT_MAX)
    {
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

