/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_environment_fopen_73b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FOPEN fopen
#else
#define FOPEN fopen
#endif

using namespace std;

namespace CWE36_Absolute_Path_Traversal__char_environment_fopen_73
{


void badSink(list<char *> dataList)
{
    /* copy data out of dataList */
    char * data = dataList.back();
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, "wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<char *> dataList)
{
    char * data = dataList.back();
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, "wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}


} /* close namespace */
