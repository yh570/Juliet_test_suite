/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_13.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyW() and SHREGSET_HKCU
 *    BadSink : Create a registry key using SHRegCreateUSKeyW() and SHREGSET_HKLM
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )


void CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HUSKEY hKey;
            /* FLAW: Call SHRegCreateUSKeyW() with SHREGSET_HKLM violating the least privilege principal */
            if (SHRegCreateUSKeyW(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        SHREGSET_HKLM) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}



/* good1() uses if(GLOBAL_CONST_FIVE!=5) instead of if(GLOBAL_CONST_FIVE==5) */
static void good1()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HUSKEY hKey;
            /* FIX: Call SHRegCreateUSKeyW() with SHREGSET_HKCU */
            if (SHRegCreateUSKeyW(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HUSKEY hKey;
            /* FIX: Call SHRegCreateUSKeyW() with SHREGSET_HKCU */
            if (SHRegCreateUSKeyW(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_13_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_13_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_13_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
