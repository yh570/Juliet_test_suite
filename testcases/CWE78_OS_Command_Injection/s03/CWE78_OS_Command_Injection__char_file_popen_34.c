/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_file_popen_34.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: file Read input from a file
 * GoodSource: Fixed string
 * Sinks: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
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
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE78_OS_Command_Injection__char_file_popen_34_unionType;


void CWE78_OS_Command_Injection__char_file_popen_34_bad()
{
    char * data;
    CWE78_OS_Command_Injection__char_file_popen_34_unionType myUnion;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
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
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE78_OS_Command_Injection__char_file_popen_34_unionType myUnion;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
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
}

void CWE78_OS_Command_Injection__char_file_popen_34_good()
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
    CWE78_OS_Command_Injection__char_file_popen_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE78_OS_Command_Injection__char_file_popen_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
