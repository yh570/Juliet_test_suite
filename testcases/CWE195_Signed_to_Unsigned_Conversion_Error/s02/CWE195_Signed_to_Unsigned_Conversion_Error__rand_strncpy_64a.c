/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Positive integer
 * Sinks: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64b_badSink(void * dataVoidPtr);

void CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64b_goodG2BSink(&data);
}

void CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64_good()
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
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
