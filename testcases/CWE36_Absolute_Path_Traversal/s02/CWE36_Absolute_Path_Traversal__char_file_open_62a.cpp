/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_file_open_62a.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Full path and file name
 * Sinks: open
 *    BadSink : Open the file named in data using open()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE36_Absolute_Path_Traversal__char_file_open_62
{


/* bad function declaration */
void badSource(char * &data);

void bad()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = "";
    data = dataBuffer;
    badSource(data);
    {
        int fileDesc;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fileDesc = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSource(char * &data);

static void goodG2B()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = "";
    data = dataBuffer;
    goodG2BSource(data);
    {
        int fileDesc;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fileDesc = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
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

using namespace CWE36_Absolute_Path_Traversal__char_file_open_62; /* so that we can use good and bad easily */

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
