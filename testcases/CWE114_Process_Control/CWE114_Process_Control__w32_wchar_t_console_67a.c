/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_console_67a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: console Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

typedef struct _CWE114_Process_Control__w32_wchar_t_console_67_structType
{
    wchar_t * structFirst;
} CWE114_Process_Control__w32_wchar_t_console_67_structType;


/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_console_67b_badSink(CWE114_Process_Control__w32_wchar_t_console_67_structType myStruct);

void CWE114_Process_Control__w32_wchar_t_console_67_bad()
{
    wchar_t * data;
    CWE114_Process_Control__w32_wchar_t_console_67_structType myStruct;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE114_Process_Control__w32_wchar_t_console_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_wchar_t_console_67b_goodG2BSink(CWE114_Process_Control__w32_wchar_t_console_67_structType myStruct);

static void goodG2B()
{
    wchar_t * data;
    CWE114_Process_Control__w32_wchar_t_console_67_structType myStruct;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    myStruct.structFirst = data;
    CWE114_Process_Control__w32_wchar_t_console_67b_goodG2BSink(myStruct);
}

void CWE114_Process_Control__w32_wchar_t_console_67_good()
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
    CWE114_Process_Control__w32_wchar_t_console_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_console_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
