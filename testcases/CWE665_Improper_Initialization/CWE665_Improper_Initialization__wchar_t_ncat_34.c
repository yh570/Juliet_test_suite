/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_34.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} CWE665_Improper_Initialization__wchar_t_ncat_34_unionType;


void CWE665_Improper_Initialization__wchar_t_ncat_34_bad()
{
    wchar_t * data;
    CWE665_Improper_Initialization__wchar_t_ncat_34_unionType myUnion;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        {
            size_t sourceLen;
            wchar_t source[100];
            wmemset(source, L'C', 100-1); /* fill with L'C's */
            source[100-1] = L'\0'; /* null terminate */
            sourceLen = wcslen(source);
            /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
            wcsncat(data, source, sourceLen);
            printWLine(data);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    CWE665_Improper_Initialization__wchar_t_ncat_34_unionType myUnion;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        {
            size_t sourceLen;
            wchar_t source[100];
            wmemset(source, L'C', 100-1); /* fill with L'C's */
            source[100-1] = L'\0'; /* null terminate */
            sourceLen = wcslen(source);
            /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
            wcsncat(data, source, sourceLen);
            printWLine(data);
        }
    }
}

void CWE665_Improper_Initialization__wchar_t_ncat_34_good()
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
    CWE665_Improper_Initialization__wchar_t_ncat_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_ncat_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
