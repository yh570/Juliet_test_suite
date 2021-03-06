/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_negative_67b.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource: negative Negative index value
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE124_Buffer_Underwrite__CWE839_negative_67_structType
{
    int structFirst;
} CWE124_Buffer_Underwrite__CWE839_negative_67_structType;


void CWE124_Buffer_Underwrite__CWE839_negative_67b_badSink(CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        int i;
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access a negative index of the array
        * This code does not check to see if the array index is negative */
        if (data < 10)
        {
            buffer[data] = 1;
            /* Print the array values */
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is negative.");
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE124_Buffer_Underwrite__CWE839_negative_67b_goodG2BSink(CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        int i;
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access a negative index of the array
        * This code does not check to see if the array index is negative */
        if (data < 10)
        {
            buffer[data] = 1;
            /* Print the array values */
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is negative.");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE124_Buffer_Underwrite__CWE839_negative_67b_goodB2GSink(CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        int i;
        int buffer[10] = { 0 };
        /* FIX: Properly validate the array index and prevent a buffer underwrite */
        if (data >= 0 && data < (10))
        {
            buffer[data] = 1;
            /* Print the array values */
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

