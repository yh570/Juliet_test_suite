/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66b_badSink(int dataArray[]);

void CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66_bad()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* FLAW: Use a negative number */
    data = -1;
    /* put data in array */
    dataArray[2] = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66b_goodG2BSink(int dataArray[]);

static void goodG2B()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    dataArray[2] = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66b_goodG2BSink(dataArray);
}

void CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66_good()
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
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_memmove_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
