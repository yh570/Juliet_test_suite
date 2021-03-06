/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_file_ifstream_68b.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sink: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <fstream>
using namespace std;

extern wchar_t * CWE23_Relative_Path_Traversal__wchar_t_file_ifstream_68_badData;
extern wchar_t * CWE23_Relative_Path_Traversal__wchar_t_file_ifstream_68_goodG2BData;

namespace CWE23_Relative_Path_Traversal__wchar_t_file_ifstream_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink()
{
    wchar_t * data = CWE23_Relative_Path_Traversal__wchar_t_file_ifstream_68_badData;
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
    wchar_t * data = CWE23_Relative_Path_Traversal__wchar_t_file_ifstream_68_goodG2BData;
    {
        ifstream inputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}


} /* close namespace */
