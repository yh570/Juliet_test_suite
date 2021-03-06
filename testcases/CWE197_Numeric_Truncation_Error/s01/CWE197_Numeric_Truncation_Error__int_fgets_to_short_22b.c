/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fgets_to_short_22b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


/* The global variable below is used to drive control flow in the source function */
extern int CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_badGlobal;

int CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_badSource(int data)
{
    if(CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_badGlobal)
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Read data from the console using fgets() */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Convert to int */
                data = atoi(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
        }
    }
    return data;
}



/* The global variables below are used to drive control flow in the source functions. */
extern int CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_goodG2B1Global;
extern int CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
int CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_goodG2B1Source(int data)
{
    if(CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
int CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_goodG2B2Source(int data)
{
    if(CWE197_Numeric_Truncation_Error__int_fgets_to_short_22_goodG2B2Global)
    {
        /* FIX: Use a positive integer less than CHAR_MAX*/
        data = CHAR_MAX-5;
    }
    return data;
}

