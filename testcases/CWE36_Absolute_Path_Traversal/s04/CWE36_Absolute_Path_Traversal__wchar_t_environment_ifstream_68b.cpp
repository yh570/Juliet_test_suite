/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_environment_ifstream_68b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sink: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
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

#include <fstream>
using namespace std;

extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_environment_ifstream_68_badData;
extern wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_environment_ifstream_68_goodG2BData;

namespace CWE36_Absolute_Path_Traversal__wchar_t_environment_ifstream_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_environment_ifstream_68_badData;
    {
        ifstream inputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink()
{
    wchar_t * data = CWE36_Absolute_Path_Traversal__wchar_t_environment_ifstream_68_goodG2BData;
    {
        ifstream inputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}


} /* close namespace */
