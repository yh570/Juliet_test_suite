/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_rand_to_char_31.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"


void CWE197_Numeric_Truncation_Error__int_rand_to_char_31_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
            char charData = (char)data;
            printHexCharLine(charData);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    {
        int dataCopy = data;
        int data = dataCopy;
        {
            /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
            char charData = (char)data;
            printHexCharLine(charData);
        }
    }
}

void CWE197_Numeric_Truncation_Error__int_rand_to_char_31_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE197_Numeric_Truncation_Error__int_rand_to_char_31_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_rand_to_char_31_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
