/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_18.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE404_Improper_Resource_Shutdown__fopen_w32_close_18_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("BadSource_fopen.txt", "w+");
    goto sink;
sink:
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the goto statement */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("BadSource_fopen.txt", "w+");
    goto sink;
sink:
    if (data != NULL)
    {
        /* FIX: Close the file using fclose() */
        fclose(data);
    }
}

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_18_good()
{
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
