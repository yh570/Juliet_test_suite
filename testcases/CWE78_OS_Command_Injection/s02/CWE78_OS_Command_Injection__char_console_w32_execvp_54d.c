/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32_execvp_54d.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sink: w32_execvp
 *    BadSink : execute command with execvp
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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
#define EXECVP _execvp

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE78_OS_Command_Injection__char_console_w32_execvp_54e_badSink(char * data);

void CWE78_OS_Command_Injection__char_console_w32_execvp_54d_badSink(char * data)
{
    CWE78_OS_Command_Injection__char_console_w32_execvp_54e_badSink(data);
}



/* good function declaration */
void CWE78_OS_Command_Injection__char_console_w32_execvp_54e_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_console_w32_execvp_54d_goodG2BSink(char * data)
{
    CWE78_OS_Command_Injection__char_console_w32_execvp_54e_goodG2BSink(data);
}

