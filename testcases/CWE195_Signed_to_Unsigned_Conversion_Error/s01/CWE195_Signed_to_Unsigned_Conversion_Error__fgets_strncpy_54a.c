/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54b_badSink(int data);

void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54_bad()
{
    int data;
    /* Initialize data */
    data = -1;
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
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54b_badSink(data);
}



/* good function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54b_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54b_goodG2BSink(data);
}

void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54_good()
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
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_strncpy_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
