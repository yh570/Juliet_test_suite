/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b_badSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b_badSink(data);
}



/* good function declarations */
void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b_goodB2GSink(FILE * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54b_goodB2GSink(data);
}

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54_good()
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
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
