/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68b.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#pragma comment(lib, "advapi32.lib")

extern wchar_t * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68_badData;
extern wchar_t * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68b_badSink()
{
    wchar_t * password = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68_badData;
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
        free(password);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68b_goodG2BSink()
{
    wchar_t * password = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_68_goodG2BData;
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
        free(password);
    }
}

