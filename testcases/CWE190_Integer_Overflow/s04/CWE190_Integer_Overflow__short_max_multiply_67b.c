/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_multiply_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__short_max_multiply_67_structType
{
    short structFirst;
} CWE190_Integer_Overflow__short_max_multiply_67_structType;


void CWE190_Integer_Overflow__short_max_multiply_67b_badSink(CWE190_Integer_Overflow__short_max_multiply_67_structType myStruct)
{
    short data = myStruct.structFirst;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > SHRT_MAX, this will overflow */
        short result = data * 2;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__short_max_multiply_67b_goodG2BSink(CWE190_Integer_Overflow__short_max_multiply_67_structType myStruct)
{
    short data = myStruct.structFirst;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > SHRT_MAX, this will overflow */
        short result = data * 2;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__short_max_multiply_67b_goodB2GSink(CWE190_Integer_Overflow__short_max_multiply_67_structType myStruct)
{
    short data = myStruct.structFirst;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < (SHRT_MAX/2))
        {
            short result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

