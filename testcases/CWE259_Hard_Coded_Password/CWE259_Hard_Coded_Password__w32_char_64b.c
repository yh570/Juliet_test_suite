/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_64b.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-64b.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "ABCD1234!"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")


void CWE259_Hard_Coded_Password__w32_char_64b_badSink(void * passwordVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * * passwordPtr = (char * *)passwordVoidPtr;
    /* dereference passwordPtr into password */
    char * password = (*passwordPtr);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* POTENTIAL FLAW: Attempt to login user with password from the source (which may be hardcoded) */
        if (LogonUserA(
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
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE259_Hard_Coded_Password__w32_char_64b_goodG2BSink(void * passwordVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * * passwordPtr = (char * *)passwordVoidPtr;
    /* dereference passwordPtr into password */
    char * password = (*passwordPtr);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* POTENTIAL FLAW: Attempt to login user with password from the source (which may be hardcoded) */
        if (LogonUserA(
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
    }
}

