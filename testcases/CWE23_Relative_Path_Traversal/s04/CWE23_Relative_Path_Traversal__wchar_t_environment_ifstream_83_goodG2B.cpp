/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83_goodG2B.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed file name
 * Sinks: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83.h"

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83
{
CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83_goodG2B::CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83_goodG2B(wchar_t * dataCopy)
{
    data = dataCopy;
    /* FIX: Use a fixed file name */
    wcscat(data, L"file.txt");
}

CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83_goodG2B::~CWE23_Relative_Path_Traversal__wchar_t_environment_ifstream_83_goodG2B()
{
    {
        ifstream inputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}
}
