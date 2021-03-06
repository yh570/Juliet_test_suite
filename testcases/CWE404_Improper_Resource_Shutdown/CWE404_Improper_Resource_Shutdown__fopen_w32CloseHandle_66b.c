/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b_badSink(FILE * dataArray[])
{
    /* copy data out of dataArray */
    FILE * data = dataArray[2];
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using CloseHandle() instead of fclose() */
        CloseHandle((HANDLE)data);
    }
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_66b_goodB2GSink(FILE * dataArray[])
{
    FILE * data = dataArray[2];
    if (data != NULL)
    {
        /* FIX: Close the file using fclose() */
        fclose(data);
    }
}

