/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_81_bad.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed file name
 * Sinks: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_81.h"

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_81
{

void CWE23_Relative_Path_Traversal__wchar_t_environment_ofstream_81_bad::action(wchar_t * data) const
{
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}

}
