/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_01.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegCreateKey
 *    GoodSink: Create a registry key using RegCreateKeyA() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )


void CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_01_bad()
{
    {
        char * keyName = "TEST\\TestKey";
        HKEY hKey;
        /* FLAW: Call RegCreateKeyA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegCreateKeyA(
                    HKEY_LOCAL_MACHINE,
                    keyName,
                    &hKey) != ERROR_SUCCESS)
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



static void good1()
{
    {
        char * keyName = "TEST\\TestKey";
        HKEY hKey;
        /* FIX: Call RegCreateKeyA() with HKEY_CURRENT_USER */
        if (RegCreateKeyA(
                    HKEY_CURRENT_USER,
                    keyName,
                    &hKey) != ERROR_SUCCESS)
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

void CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_01_good()
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
    CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_char_RegCreateKey_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
