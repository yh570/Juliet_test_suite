/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_64a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_64b_badSink(void * dataVoidPtr);

void CWE665_Improper_Initialization__wchar_t_cat_64_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    CWE665_Improper_Initialization__wchar_t_cat_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__wchar_t_cat_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    CWE665_Improper_Initialization__wchar_t_cat_64b_goodG2BSink(&data);
}

void CWE665_Improper_Initialization__wchar_t_cat_64_good()
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
    CWE665_Improper_Initialization__wchar_t_cat_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
