/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_wchar_t_RegCreateKeyEx_18.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: RegCreateKeyEx
 *    GoodSink: Create a registry key using RegCreateKeyExW() without excessive privileges
 *    BadSink : Create a registry key using RegCreateKeyExW() with excessive privileges
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )


void CWE284_Improper_Access_Control__w32_wchar_t_RegCreateKeyEx_18_bad()
{
    goto sink;
sink:
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FLAW: Call RegCreateKeyExW() with KEY_ALL_ACCESS as the 6th parameter */
        if (RegCreateKeyExW(
                    HKEY_CURRENT_USER,
                    keyName,
                    0,
                    NULL,
                    REG_OPTION_NON_VOLATILE,
                    KEY_ALL_ACCESS,
                    NULL,
                    &hKey,
                    NULL) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be created");
        }
        else
        {
            printLine("Registry key created successfully");
            RegCloseKey(hKey);
        }
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FIX: Call RegCreateKeyExW() without KEY_ALL_ACCESS as the 6th parameter to limit access */
        if (RegCreateKeyExW(
                    HKEY_CURRENT_USER,
                    keyName,
                    0,
                    NULL,
                    REG_OPTION_NON_VOLATILE,
                    KEY_WRITE,
                    NULL,
                    &hKey,
                    NULL) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be created");
        }
        else
        {
            printLine("Registry key created successfully");
            RegCloseKey(hKey);
        }
    }
}

void CWE284_Improper_Access_Control__w32_wchar_t_RegCreateKeyEx_18_good()
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
    CWE284_Improper_Access_Control__w32_wchar_t_RegCreateKeyEx_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_wchar_t_RegCreateKeyEx_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
