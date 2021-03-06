/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_ifstream_82_bad.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sinks: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__char_file_ifstream_82.h"

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__char_file_ifstream_82
{

void CWE23_Relative_Path_Traversal__char_file_ifstream_82_bad::action(char * data)
{
    {
        ifstream inputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}

}
