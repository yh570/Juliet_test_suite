/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84_goodG2B.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sinks: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84.h"

#include <windows.h>

namespace CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84
{
CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84_goodG2B::CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84_goodG2B(wchar_t * dataCopy)
{
    data = dataCopy;
#ifdef _WIN32
    /* FIX: Use a fixed, full path and file name */
    wcscat(data, L"c:\\temp\\file.txt");
#else
    /* FIX: Use a fixed, full path and file name */
    wcscat(data, L"/tmp/file.txt");
#endif
}

CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84_goodG2B::~CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_84_goodG2B()
{
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileW(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}
}
