/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_16.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE665_Improper_Initialization__char_ncat_16_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    while(1)
    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    }
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
    }
}



/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    while(1)
    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
        break;
    }
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
    }
}

void CWE665_Improper_Initialization__char_ncat_16_good()
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
    CWE665_Improper_Initialization__char_ncat_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_ncat_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
