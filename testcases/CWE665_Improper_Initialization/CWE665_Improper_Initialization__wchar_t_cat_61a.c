/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_61a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
wchar_t * CWE665_Improper_Initialization__wchar_t_cat_61b_badSource(wchar_t * data);

void CWE665_Improper_Initialization__wchar_t_cat_61_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    data = CWE665_Improper_Initialization__wchar_t_cat_61b_badSource(data);
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE665_Improper_Initialization__wchar_t_cat_61b_goodG2BSource(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    data = CWE665_Improper_Initialization__wchar_t_cat_61b_goodG2BSource(data);
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_61_good()
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
    CWE665_Improper_Initialization__wchar_t_cat_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
