/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_53d.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-53d.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed file name
 * Sink: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#ifdef _WIN32
#define FOPEN _wfopen
#else
#define FOPEN fopen
#endif

namespace CWE23_Relative_Path_Traversal__wchar_t_environment_fopen_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink_d(wchar_t * data)
{
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, L"wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(wchar_t * data)
{
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, L"wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}


} /* close namespace */
