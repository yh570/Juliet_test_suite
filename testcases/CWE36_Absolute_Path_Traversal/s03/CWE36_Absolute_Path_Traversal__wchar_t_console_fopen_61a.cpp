/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_console_fopen_61a.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-61a.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FOPEN _wfopen
#else
#define FOPEN fopen
#endif

namespace CWE36_Absolute_Path_Traversal__wchar_t_console_fopen_61
{


/* bad function declaration */
wchar_t * badSource(wchar_t * data);

void bad()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    data = badSource(data);
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
wchar_t * goodG2BSource(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = L"";
    data = dataBuffer;
    data = goodG2BSource(data);
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

using namespace CWE36_Absolute_Path_Traversal__wchar_t_console_fopen_61; /* so that we can use good and bad easily */

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
