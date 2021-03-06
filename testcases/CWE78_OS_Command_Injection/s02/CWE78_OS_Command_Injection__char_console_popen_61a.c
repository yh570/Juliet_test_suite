/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_popen_61a.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
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


/* bad function declaration */
char * CWE78_OS_Command_Injection__char_console_popen_61b_badSource(char * data);

void CWE78_OS_Command_Injection__char_console_popen_61_bad()
{
    char * data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    data = CWE78_OS_Command_Injection__char_console_popen_61b_badSource(data);
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, "w");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
char * CWE78_OS_Command_Injection__char_console_popen_61b_goodG2BSource(char * data);

static void goodG2B()
{
    char * data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    data = CWE78_OS_Command_Injection__char_console_popen_61b_goodG2BSource(data);
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, "w");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

void CWE78_OS_Command_Injection__char_console_popen_61_good()
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
    CWE78_OS_Command_Injection__char_console_popen_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_console_popen_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
