/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_badSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b_badSink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_badSink(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_goodB2GSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53b_goodB2GSink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_53c_goodB2GSink(data);
}

