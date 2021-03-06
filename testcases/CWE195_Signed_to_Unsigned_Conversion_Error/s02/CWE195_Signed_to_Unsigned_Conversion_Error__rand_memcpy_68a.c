/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_badData;
int CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_goodG2BData;


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68b_badSink();

void CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_badData = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68b_badSink();
}



/* good function declarations */
void CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_goodG2BData = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68b_goodG2BSink();
}

void CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_good()
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
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__rand_memcpy_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
