/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_CreateProcess_08.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: CreateProcess
 *    GoodSink: Create a process using CreateProcessA() with quotes for the executable path
 *    BadSink : Create a process using CreateProcessA() without quotes for the executable path
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}


void CWE272_Least_Privilege_Violation__w32_char_CreateProcess_08_bad()
{
    if(staticReturnsTrue())
    {
        {
            STARTUPINFOA si;
            PROCESS_INFORMATION pi;
            /* FLAW: The commandLine parameter to CreateProcess() contains a space in it and does not
               surround the executable path with quotes.  A malicious executable could be run because
               of the way the function parses spaces. The process will attempt to run "Program.exe,"
               if it exists, instead of the intended "GoodApp.exe" */
            if( !CreateProcessA(NULL,
                                "C:\\Program Files\\GoodApp arg1 arg2",
                                NULL,
                                NULL,
                                FALSE,
                                0,
                                NULL,
                                NULL,
                                &si,
                                &pi))
            {
                printLine("CreateProcess failed");
                return;
            }
            else
            {
                printLine("CreateProcess successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    }
}



/* good1() uses if(staticReturnsFalse()) instead of if(staticReturnsTrue()) */
static void good1()
{
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            STARTUPINFOA si;
            PROCESS_INFORMATION pi;
            /* FIX: The commandLine parameter to CreateProcess() contains quotes surrounding the
               executable path. */
            if( !CreateProcessA(NULL,
                                "\"C:\\Program Files\\GoodApp\" arg1 arg2",
                                NULL,
                                NULL,
                                FALSE,
                                0,
                                NULL,
                                NULL,
                                &si,
                                &pi))
            {
                printf( "CreateProcess failed (%d).\n", GetLastError() );
                return;
            }
            else
            {
                printLine("CreateProcess successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticReturnsTrue())
    {
        {
            STARTUPINFOA si;
            PROCESS_INFORMATION pi;
            /* FIX: The commandLine parameter to CreateProcess() contains quotes surrounding the
               executable path. */
            if( !CreateProcessA(NULL,
                                "\"C:\\Program Files\\GoodApp\" arg1 arg2",
                                NULL,
                                NULL,
                                FALSE,
                                0,
                                NULL,
                                NULL,
                                &si,
                                &pi))
            {
                printf( "CreateProcess failed (%d).\n", GetLastError() );
                return;
            }
            else
            {
                printLine("CreateProcess successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_char_CreateProcess_08_good()
{
    good1();
    good2();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE272_Least_Privilege_Violation__w32_char_CreateProcess_08_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_char_CreateProcess_08_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
