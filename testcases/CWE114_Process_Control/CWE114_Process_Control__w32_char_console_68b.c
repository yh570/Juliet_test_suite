/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_console_68b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: console Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

extern char * CWE114_Process_Control__w32_char_console_68_badData;
extern char * CWE114_Process_Control__w32_char_console_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE114_Process_Control__w32_char_console_68b_badSink()
{
    char * data = CWE114_Process_Control__w32_char_console_68_badData;
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



/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_char_console_68b_goodG2BSink()
{
    char * data = CWE114_Process_Control__w32_char_console_68_goodG2BData;
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

