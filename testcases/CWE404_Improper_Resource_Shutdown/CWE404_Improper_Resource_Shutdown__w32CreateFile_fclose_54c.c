/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_badSink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_badSink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_badSink(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_goodB2GSink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_goodB2GSink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54d_goodB2GSink(data);
}

