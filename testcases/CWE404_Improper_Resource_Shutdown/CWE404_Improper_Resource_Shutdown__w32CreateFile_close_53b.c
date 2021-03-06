/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_badSink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b_badSink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_badSink(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_goodB2GSink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53b_goodB2GSink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_53c_goodB2GSink(data);
}

