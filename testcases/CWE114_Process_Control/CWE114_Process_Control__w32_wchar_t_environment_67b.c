/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_environment_67b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: environment Read input from an environment variable
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <windows.h>

typedef struct _CWE114_Process_Control__w32_wchar_t_environment_67_structType
{
    wchar_t * structFirst;
} CWE114_Process_Control__w32_wchar_t_environment_67_structType;


void CWE114_Process_Control__w32_wchar_t_environment_67b_badSink(CWE114_Process_Control__w32_wchar_t_environment_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        HMODULE hModule;
        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryW(data);
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
void CWE114_Process_Control__w32_wchar_t_environment_67b_goodG2BSink(CWE114_Process_Control__w32_wchar_t_environment_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        HMODULE hModule;
        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryW(data);
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

