/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE244_Heap_Inspection__w32_char_free_14.c
Label Definition File: CWE244_Heap_Inspection__w32.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 244 Failure to Clear Heap Before Release (Heap Inspection)
 * Sinks: free
 *    GoodSink: Clear the password buffer before releasing the memory from the heap
 *    BadSink : Release password from the heap without first clearing the buffer
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>
#pragma comment(lib, "advapi32.lib")


void CWE244_Heap_Inspection__w32_char_free_14_bad()
{
    if(globalFive==5)
    {
        {
            char * password = (char *)malloc(100*sizeof(char));
            if (password == NULL) {exit(-1);}
            size_t passwordLen = 0;
            HANDLE hUser;
            char * username = "User";
            char * domain = "Domain";
            /* Initialize password */
            password[0] = '\0';
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
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
            /* FLAW: free() password without clearing the password buffer */
            free(password);
        }
    }
}



/* good1() uses if(globalFive!=5) instead of if(globalFive==5) */
static void good1()
{
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * password = (char *)malloc(100*sizeof(char));
            if (password == NULL) {exit(-1);}
            size_t passwordLen = 0;
            HANDLE hUser;
            char * username = "User";
            char * domain = "Domain";
            /* Initialize password */
            password[0] = '\0';
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
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
            passwordLen = strlen(password);
            /* FIX: Clear password prior to freeing */
            SecureZeroMemory(password, passwordLen * sizeof(char));
            free(password);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalFive==5)
    {
        {
            char * password = (char *)malloc(100*sizeof(char));
            if (password == NULL) {exit(-1);}
            size_t passwordLen = 0;
            HANDLE hUser;
            char * username = "User";
            char * domain = "Domain";
            /* Initialize password */
            password[0] = '\0';
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
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
            passwordLen = strlen(password);
            /* FIX: Clear password prior to freeing */
            SecureZeroMemory(password, passwordLen * sizeof(char));
            free(password);
        }
    }
}

void CWE244_Heap_Inspection__w32_char_free_14_good()
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
    CWE244_Heap_Inspection__w32_char_free_14_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE244_Heap_Inspection__w32_char_free_14_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
