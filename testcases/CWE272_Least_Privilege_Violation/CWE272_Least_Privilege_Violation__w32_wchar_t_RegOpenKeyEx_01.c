/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_01.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegOpenKeyEx
 *    GoodSink: Open a registry key using RegOpenKeyExW() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using RegOpenKeyExW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )


void CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_01_bad()
{
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FLAW: Call RegOpenKeyExW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegOpenKeyExW(
                    HKEY_LOCAL_MACHINE,
                    keyName,
                    0,
                    KEY_WRITE,
                    &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else
        {
            printLine("Registry key opened successfully");
            RegCloseKey(hKey);
        }
    }
}



static void good1()
{
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FIX: Call RegOpenKeyExW() with HKEY_CURRENT_USER */
        if (RegOpenKeyExW(
                    HKEY_CURRENT_USER,
                    keyName,
                    0,
                    KEY_WRITE,
                    &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else
        {
            printLine("Registry key opened successfully");
            RegCloseKey(hKey);
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_01_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegOpenKeyEx_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
