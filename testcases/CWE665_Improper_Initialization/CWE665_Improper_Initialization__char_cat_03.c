/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_03.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-03.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using strcat
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE665_Improper_Initialization__char_cat_03_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(5==5)
    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}



/* goodG2B1() - use goodsource and badsink by changing the 5==5 to 5!=5 */
static void goodG2B1()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(5==5)
    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}

void CWE665_Improper_Initialization__char_cat_03_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE665_Improper_Initialization__char_cat_03_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_cat_03_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
