/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_console_ofstream_62a.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed file name
 * Sinks: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_console_ofstream_62
{


/* bad function declaration */
void badSource(wchar_t * &data);

void bad()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    badSource(data);
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSource(wchar_t * &data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    goodG2BSource(data);
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE23_Relative_Path_Traversal__wchar_t_console_ofstream_62; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
