/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE615_Info_Exposure_by_Comment__w32_10.c
Label Definition File: CWE615_Info_Exposure_by_Comment__w32.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 615 Information Exposure by Comment
 * Sinks:
 *    GoodSink: Do not place username and password in comment
 *    BadSink : Information exposure by comment
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#define PASSWORD "ABCD1234!"
#define USERNAME "XXXXX Smith!"


void CWE615_Info_Exposure_by_Comment__w32_10_bad()
{
    if(globalTrue)
    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FLAW: expose username and password in comment*/
                /* Logged in XXXXX Smith using password ABCD1234 */
                printLine("User logged in successfully" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}



/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FIX: do not expose username or password in comment */
                /* User logged in successfully */
                printLine("User logged in successfully with password" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FIX: do not expose username or password in comment */
                /* User logged in successfully */
                printLine("User logged in successfully with password" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

void CWE615_Info_Exposure_by_Comment__w32_10_good()
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
    CWE615_Info_Exposure_by_Comment__w32_10_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE615_Info_Exposure_by_Comment__w32_10_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
