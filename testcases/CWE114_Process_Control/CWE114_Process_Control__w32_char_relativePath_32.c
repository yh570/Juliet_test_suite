/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_32.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>


void CWE114_Process_Control__w32_char_relativePath_32_bad()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        char * data = *dataPtr1;
        /* FLAW: Specify just the file name for the library, not the full path */
        strcpy(data, "winsrv.dll");
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            HMODULE hModule;
            /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
             * replace his own file with the intended library */
            hModule = LoadLibraryA(data);
            if (hModule != NULL)
            {
                FreeLibrary(hModule);
                printLine("Library loaded and freed successfully");
            }
            else
            {
                printLine("Unable to load library");
            }
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        char * data = *dataPtr1;
        /* FIX: Specify the full pathname for the library */
        strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            HMODULE hModule;
            /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
             * replace his own file with the intended library */
            hModule = LoadLibraryA(data);
            if (hModule != NULL)
            {
                FreeLibrary(hModule);
                printLine("Library loaded and freed successfully");
            }
            else
            {
                printLine("Unable to load library");
            }
        }
    }
}

void CWE114_Process_Control__w32_char_relativePath_32_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE114_Process_Control__w32_char_relativePath_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_char_relativePath_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
