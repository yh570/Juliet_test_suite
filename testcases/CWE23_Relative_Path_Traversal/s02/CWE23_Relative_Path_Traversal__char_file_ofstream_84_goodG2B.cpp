/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_ofstream_84_goodG2B.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sinks: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__char_file_ofstream_84.h"

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__char_file_ofstream_84
{
CWE23_Relative_Path_Traversal__char_file_ofstream_84_goodG2B::CWE23_Relative_Path_Traversal__char_file_ofstream_84_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: Use a fixed file name */
    strcat(data, "file.txt");
}

CWE23_Relative_Path_Traversal__char_file_ofstream_84_goodG2B::~CWE23_Relative_Path_Traversal__char_file_ofstream_84_goodG2B()
{
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}
}
