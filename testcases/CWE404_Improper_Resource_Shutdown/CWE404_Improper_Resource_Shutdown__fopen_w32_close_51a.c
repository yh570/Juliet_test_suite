/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_51a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b_badSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_51_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b_badSink(data);
}



/* good function declarations */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b_goodB2GSink(FILE * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_51b_goodB2GSink(data);
}

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_51_good()
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
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_51_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_51_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
