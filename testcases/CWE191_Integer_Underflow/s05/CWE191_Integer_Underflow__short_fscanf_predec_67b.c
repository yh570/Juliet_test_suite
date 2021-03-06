/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_fscanf_predec_67b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE191_Integer_Underflow__short_fscanf_predec_67_structType
{
    short structFirst;
} CWE191_Integer_Underflow__short_fscanf_predec_67_structType;


void CWE191_Integer_Underflow__short_fscanf_predec_67b_badSink(CWE191_Integer_Underflow__short_fscanf_predec_67_structType myStruct)
{
    short data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        short result = data;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__short_fscanf_predec_67b_goodG2BSink(CWE191_Integer_Underflow__short_fscanf_predec_67_structType myStruct)
{
    short data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        short result = data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__short_fscanf_predec_67b_goodB2GSink(CWE191_Integer_Underflow__short_fscanf_predec_67_structType myStruct)
{
    short data = myStruct.structFirst;
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > SHRT_MIN)
    {
        --data;
        short result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

