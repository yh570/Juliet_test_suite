/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_66a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE665_Improper_Initialization__char_ncat_66b_badSink(char * dataArray[]);

void CWE665_Improper_Initialization__char_ncat_66_bad()
{
    char * data;
    char * dataArray[5];
    char dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    /* put data in array */
    dataArray[2] = data;
    CWE665_Improper_Initialization__char_ncat_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__char_ncat_66b_goodG2BSink(char * dataArray[]);

static void goodG2B()
{
    char * data;
    char * dataArray[5];
    char dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    dataArray[2] = data;
    CWE665_Improper_Initialization__char_ncat_66b_goodG2BSink(dataArray);
}

void CWE665_Improper_Initialization__char_ncat_66_good()
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
    CWE665_Improper_Initialization__char_ncat_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_ncat_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
