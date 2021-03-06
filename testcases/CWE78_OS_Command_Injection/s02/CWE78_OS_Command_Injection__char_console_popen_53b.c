/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_popen_53b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sink: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE78_OS_Command_Injection__char_console_popen_53c_badSink(char * data);

void CWE78_OS_Command_Injection__char_console_popen_53b_badSink(char * data)
{
    CWE78_OS_Command_Injection__char_console_popen_53c_badSink(data);
}



/* good function declaration */
void CWE78_OS_Command_Injection__char_console_popen_53c_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_console_popen_53b_goodG2BSink(char * data)
{
    CWE78_OS_Command_Injection__char_console_popen_53c_goodG2BSink(data);
}

