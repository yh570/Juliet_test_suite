/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__negative_malloc_64a.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__negative_malloc_64b_badSink(void * dataVoidPtr);

void CWE194_Unexpected_Sign_Extension__negative_malloc_64_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FLAW: Use a negative number */
    data = -1;
    CWE194_Unexpected_Sign_Extension__negative_malloc_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__negative_malloc_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    CWE194_Unexpected_Sign_Extension__negative_malloc_64b_goodG2BSink(&data);
}

void CWE194_Unexpected_Sign_Extension__negative_malloc_64_good()
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
    CWE194_Unexpected_Sign_Extension__negative_malloc_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__negative_malloc_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
