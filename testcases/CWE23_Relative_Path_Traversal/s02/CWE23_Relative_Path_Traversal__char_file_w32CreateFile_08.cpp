/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_w32CreateFile_08.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sink: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

namespace CWE23_Relative_Path_Traversal__char_file_w32CreateFile_08
{


void bad()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    if(staticReturnsTrue())
    {
        {
            /* Read input from a file */
            size_t dataLen = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (FILENAME_MAX-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgets(data+dataLen, (int)(FILENAME_MAX-dataLen), pFile) == NULL)
                    {
                        printLine("fgets() failed");
                        /* Restore NUL terminator if fgets fails */
                        data[dataLen] = '\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}



/* goodG2B1() - use goodsource and badsink by changing the staticReturnsTrue() to staticReturnsFalse() */
static void goodG2B1()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a fixed file name */
        strcat(data, "file.txt");
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    if(staticReturnsTrue())
    {
        /* FIX: Use a fixed file name */
        strcat(data, "file.txt");
    }
    {
        HANDLE hFile;
        /* POTENTIAL FLAW: Possibly creating and opening a file without validating the file name or path */
        hFile = CreateFileA(data,
                            (GENERIC_WRITE|GENERIC_READ),
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
        }
    }
}

void good()
{
    goodG2B1();
    goodG2B2();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE23_Relative_Path_Traversal__char_file_w32CreateFile_08; /* so that we can use good and bad easily */

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
