/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_system_54c.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sink: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
#endif

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE78_OS_Command_Injection__char_console_system_54d_badSink(char * data);

void CWE78_OS_Command_Injection__char_console_system_54c_badSink(char * data)
{
    CWE78_OS_Command_Injection__char_console_system_54d_badSink(data);
}



/* good function declaration */
void CWE78_OS_Command_Injection__char_console_system_54d_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_console_system_54c_goodG2BSink(char * data)
{
    CWE78_OS_Command_Injection__char_console_system_54d_goodG2BSink(data);
}

