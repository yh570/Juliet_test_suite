/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_31.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE665_Improper_Initialization__wchar_t_cat_31_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        {
            wchar_t source[100];
            wmemset(source, L'C', 100-1); /* fill with L'C's */
            source[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
            wcscat(data, source);
            printWLine(data);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        {
            wchar_t source[100];
            wmemset(source, L'C', 100-1); /* fill with L'C's */
            source[100-1] = L'\0'; /* null terminate */
            /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
            wcscat(data, source);
            printWLine(data);
        }
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_31_good()
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
    CWE665_Improper_Initialization__wchar_t_cat_31_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_31_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
