/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_bad.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81.h"

#include <windows.h>

namespace CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81
{

void CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_81_bad::action(FILE * data) const
{
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using CloseHandle() instead of fclose() */
        CloseHandle((HANDLE)data);
    }
}

}
