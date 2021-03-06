/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32_execv_67b.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: w32_execv
 *    BadSink : execute command with execv
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT "cmd.exe"
#define COMMAND_ARG1 "/c"
#define COMMAND_ARG2 "dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_INT "sh"
#define COMMAND_ARG1 "-c"
#define COMMAND_ARG2 "ls "
#define COMMAND_ARG3 data
#endif

#include <process.h>
#define EXECV _execv

typedef struct _CWE78_OS_Command_Injection__char_console_w32_execv_67_structType
{
    char * structFirst;
} CWE78_OS_Command_Injection__char_console_w32_execv_67_structType;


void CWE78_OS_Command_Injection__char_console_w32_execv_67b_badSink(CWE78_OS_Command_Injection__char_console_w32_execv_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* execv - specify the path where the command is located */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECV(COMMAND_INT_PATH, args);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_console_w32_execv_67b_goodG2BSink(CWE78_OS_Command_Injection__char_console_w32_execv_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* execv - specify the path where the command is located */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECV(COMMAND_INT_PATH, args);
    }
}

