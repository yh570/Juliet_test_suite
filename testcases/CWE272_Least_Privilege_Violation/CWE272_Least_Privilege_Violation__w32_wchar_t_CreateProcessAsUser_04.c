/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_CreateProcessAsUser_04.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: CreateProcessAsUser
 *    GoodSink: Create a process using CreateProcessAsUserW() with quotes for the executable path
 *    BadSink : Create a process using CreateProcessAsUserW() without quotes for the executable path
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */


void CWE272_Least_Privilege_Violation__w32_wchar_t_CreateProcessAsUser_04_bad()
{
    if(STATIC_CONST_TRUE)
    {
        {
            STARTUPINFOW si;
            PROCESS_INFORMATION pi;
            HANDLE pHandle = NULL;
            /* FLAW: The commandLine parameter to CreateProcessAsUser() contains a space in it and does not
               surround the executable path with quotes.  A malicious executable could be run because of the
               way the function parses spaces. The process will attempt to run "Program.exe," if it exists,
               instead of the intended "GoodApp.exe"  */
            if(!CreateProcessAsUserW(pHandle,
                                     NULL,
                                     L"C:\\Program Files\\GoodApp arg1 arg2",
                                     NULL,
                                     NULL,
                                     FALSE,
                                     DETACHED_PROCESS,
                                     NULL,
                                     NULL,
                                     &si,
                                     &pi))
            {
                printLine("CreateProcessAsUser failed");
                RevertToSelf();
                CloseHandle(pHandle);
                return;
            }
            else
            {
                printLine("CreateProcessAUser successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            CloseHandle(pHandle);
        }
    }
}



/* good1() uses if(STATIC_CONST_FALSE) instead of if(STATIC_CONST_TRUE) */
static void good1()
{
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            STARTUPINFOW si;
            PROCESS_INFORMATION pi;
            HANDLE pHandle = NULL;
            /* FIX: The commandLine parameter to CreateProcessAsUser() contains quotes surrounding
               the executable path. */
            if(!CreateProcessAsUserW(pHandle,
                                     NULL,
                                     L"\"C:\\Program Files\\GoodApp\" arg1 arg2",
                                     NULL,
                                     NULL,
                                     FALSE,
                                     DETACHED_PROCESS,
                                     NULL,
                                     NULL,
                                     &si,
                                     &pi))
            {
                printLine("CreateProcessAsUser failed");
                RevertToSelf();
                CloseHandle(pHandle);
                return;
            }
            else
            {
                printLine("CreateProcessAUser successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            CloseHandle(pHandle);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(STATIC_CONST_TRUE)
    {
        {
            STARTUPINFOW si;
            PROCESS_INFORMATION pi;
            HANDLE pHandle = NULL;
            /* FIX: The commandLine parameter to CreateProcessAsUser() contains quotes surrounding
               the executable path. */
            if(!CreateProcessAsUserW(pHandle,
                                     NULL,
                                     L"\"C:\\Program Files\\GoodApp\" arg1 arg2",
                                     NULL,
                                     NULL,
                                     FALSE,
                                     DETACHED_PROCESS,
                                     NULL,
                                     NULL,
                                     &si,
                                     &pi))
            {
                printLine("CreateProcessAsUser failed");
                RevertToSelf();
                CloseHandle(pHandle);
                return;
            }
            else
            {
                printLine("CreateProcessAUser successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            CloseHandle(pHandle);
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_wchar_t_CreateProcessAsUser_04_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_CreateProcessAsUser_04_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_CreateProcessAsUser_04_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
