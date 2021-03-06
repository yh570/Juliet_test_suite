/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_68b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sink: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <windows.h>

extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_68_badData;
extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_68_goodG2BData;

namespace CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_68_badData;
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



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_environment_w32CreateFile_68_goodG2BData;
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


} /* close namespace */
