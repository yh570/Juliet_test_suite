/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_15.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegCreateKey
 *    GoodSink: Create a registry key using RegCreateKeyW() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )


void CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_15_bad()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FLAW: Call RegCreateKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegCreateKeyW(
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}



/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
        if (RegCreateKeyW(
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
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HKEY hKey;
        /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
        if (RegCreateKeyW(
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_15_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
