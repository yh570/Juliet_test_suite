/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_file_73a.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: file Read input from a file
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

using namespace std;

namespace CWE114_Process_Control__w32_wchar_t_file_73
{


/* bad function declaration */
void badSink(list<wchar_t *> dataList);

void bad()
{
    wchar_t * data;
    list<wchar_t *> dataList;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}



/* good function declarations */

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<wchar_t *> dataList);

static void goodG2B()
{
    wchar_t * data;
    list<wchar_t *> dataList;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    goodG2BSink(dataList);
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE114_Process_Control__w32_wchar_t_file_73; /* so that we can use good and bad easily */

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
