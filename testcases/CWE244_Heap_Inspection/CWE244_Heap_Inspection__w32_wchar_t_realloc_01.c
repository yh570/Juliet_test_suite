/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE244_Heap_Inspection__w32_wchar_t_realloc_01.c
Label Definition File: CWE244_Heap_Inspection__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 244 Failure to Clear Heap Before Release (Heap Inspection)
 * Sinks: realloc
 *    GoodSink: Clear the password buffer before reallocating it
 *    BadSink : Reallocate buffer containing password without first clearing the buffer
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>
#pragma comment(lib, "advapi32.lib")


void CWE244_Heap_Inspection__w32_wchar_t_realloc_01_bad()
{
    {
        wchar_t * password = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (password == NULL) {exit(-1);}
        size_t passwordLen = 0;
        HANDLE hUser;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Initialize password */
        password[0] = L'\0';
        if (fgetws(password, 100, stdin) == NULL)
        {
            printLine("fgetws() failed");
            /* Restore NUL terminator if fgetws fails */
            password[0] = L'\0';
        }
        /* Remove the carriage return from the string that is inserted by fgetws() */
        passwordLen = wcslen(password);
        if (passwordLen > 0)
        {
            password[passwordLen-1] = L'\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &hUser) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(hUser);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* FLAW: reallocate password without clearing the password buffer
         * which could leave a copy of the password in memory */
        password = realloc(password, 200 * sizeof(wchar_t));
        if (password == NULL) {exit(-1);}
        /* Zeroize the password */
        SecureZeroMemory(password, 200 * sizeof(wchar_t));
        /* Use the password buffer again */
        wcscpy(password, L"Nothing to see here");
        printWLine(password);
        free(password);
    }
}



static void good1()
{
    {
        wchar_t * password = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (password == NULL) {exit(-1);}
        size_t passwordLen = 0;
        HANDLE hUser;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Initialize password */
        password[0] = L'\0';
        if (fgetws(password, 100, stdin) == NULL)
        {
            printLine("fgetws() failed");
            /* Restore NUL terminator if fgetws fails */
            password[0] = L'\0';
        }
        /* Remove the carriage return from the string that is inserted by fgetws() */
        passwordLen = wcslen(password);
        if (passwordLen > 0)
        {
            password[passwordLen-1] = L'\0';
        }
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &hUser) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(hUser);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* FIX: Zeroize the password buffer before reallocating it */
        SecureZeroMemory(password, 100 * sizeof(wchar_t));
        password = realloc(password, 200 * sizeof(wchar_t));
        if (password == NULL) {exit(-1);}
        /* Use the password buffer again */
        wcscpy(password, L"Nothing to see here");
        printWLine(password);
        free(password);
    }
}

void CWE244_Heap_Inspection__w32_wchar_t_realloc_01_good()
{
    good1();
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
    CWE244_Heap_Inspection__w32_wchar_t_realloc_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE244_Heap_Inspection__w32_wchar_t_realloc_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
