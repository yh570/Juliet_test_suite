/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_environment_66a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: environment Read input from an environment variable
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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


/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_environment_66b_badSink(wchar_t * dataArray[]);

void CWE114_Process_Control__w32_wchar_t_environment_66_bad()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
    /* put data in array */
    dataArray[2] = data;
    CWE114_Process_Control__w32_wchar_t_environment_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_wchar_t_environment_66b_goodG2BSink(wchar_t * dataArray[]);

static void goodG2B()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    dataArray[2] = data;
    CWE114_Process_Control__w32_wchar_t_environment_66b_goodG2BSink(dataArray);
}

void CWE114_Process_Control__w32_wchar_t_environment_66_good()
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
    CWE114_Process_Control__w32_wchar_t_environment_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_environment_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
