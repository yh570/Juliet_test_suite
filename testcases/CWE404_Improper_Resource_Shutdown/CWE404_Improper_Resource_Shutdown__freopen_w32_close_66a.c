/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_66a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b_badSink(FILE * dataArray[]);

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_66_bad()
{
    FILE * data;
    FILE * dataArray[5];
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* put data in array */
    dataArray[2] = data;
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b_badSink(dataArray);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b_goodB2GSink(FILE * dataArray[]);

static void goodB2G()
{
    FILE * data;
    FILE * dataArray[5];
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    dataArray[2] = data;
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_66b_goodB2GSink(dataArray);
}

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_66_good()
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
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
