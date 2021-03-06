/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_53a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-53a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using strcat
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE665_Improper_Initialization__char_cat_53b_badSink(char * data);

void CWE665_Improper_Initialization__char_cat_53_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    CWE665_Improper_Initialization__char_cat_53b_badSink(data);
}



/* good function declaration */
void CWE665_Improper_Initialization__char_cat_53b_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    CWE665_Improper_Initialization__char_cat_53b_goodG2BSink(data);
}

void CWE665_Improper_Initialization__char_cat_53_good()
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
    CWE665_Improper_Initialization__char_cat_53_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_cat_53_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
