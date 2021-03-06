/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_system_67a.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE78_OS_Command_Injection__char_console_system_67_structType
{
    char * structFirst;
} CWE78_OS_Command_Injection__char_console_system_67_structType;


/* bad function declaration */
void CWE78_OS_Command_Injection__char_console_system_67b_badSink(CWE78_OS_Command_Injection__char_console_system_67_structType myStruct);

void CWE78_OS_Command_Injection__char_console_system_67_bad()
{
    char * data;
    CWE78_OS_Command_Injection__char_console_system_67_structType myStruct;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        /* Read input from the console */
        size_t dataLen = strlen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgets() */
                dataLen = strlen(data);
                if (dataLen > 0 && data[dataLen-1] == '\n')
                {
                    data[dataLen-1] = '\0';
                }
            }
            else
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                data[dataLen] = '\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE78_OS_Command_Injection__char_console_system_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_console_system_67b_goodG2BSink(CWE78_OS_Command_Injection__char_console_system_67_structType myStruct);

static void goodG2B()
{
    char * data;
    CWE78_OS_Command_Injection__char_console_system_67_structType myStruct;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
    myStruct.structFirst = data;
    CWE78_OS_Command_Injection__char_console_system_67b_goodG2BSink(myStruct);
}

void CWE78_OS_Command_Injection__char_console_system_67_good()
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
    CWE78_OS_Command_Injection__char_console_system_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_console_system_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
