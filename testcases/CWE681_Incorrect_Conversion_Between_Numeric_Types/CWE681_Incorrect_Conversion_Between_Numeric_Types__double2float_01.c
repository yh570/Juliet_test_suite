/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01.c
Label Definition File: CWE681_Incorrect_Conversion_Between_Numeric_Types.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 681 Incorrect Conversion Between Numeric Types
 * Sinks: double2float
 *    GoodSink: check for conversion error
 *    BadSink : explicit cast
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <float.h>
#define CHAR_ARRAY_SIZE 256


void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01_bad()
{
    {
        char inputBuffer[CHAR_ARRAY_SIZE];
        double doubleNumber = 0;
        /* Enter: 1e-50, result should be 0.0 (for bad case)
         *
         * Note: alternate input
         * 999999999999999999999999999999999999999999999999999999999999999
         */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Read a double */
            doubleNumber = atof(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
        /* FLAW: should not cast without checking if conversion is safe */
        printFloatLine((float)doubleNumber);
    }
}



static void good1()
{
    {
        char inputBuffer[CHAR_ARRAY_SIZE];
        double doubleNumber = 0;
        /* Enter: 1e-50, result should be 0.0 (for bad case)
         *
         * Note: alternate input
         * 999999999999999999999999999999999999999999999999999999999999999
         */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Read a double */
            doubleNumber = atof(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
        /* FIX: check to make sure conversion is safe */
        if (doubleNumber > FLT_MAX || doubleNumber < FLT_MIN)
        {
            printLine("Value is too small or large to be represented as a float");
        }
        else
        {
            printFloatLine((float)doubleNumber);
        }
    }
}

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01_good()
{
    good1();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
