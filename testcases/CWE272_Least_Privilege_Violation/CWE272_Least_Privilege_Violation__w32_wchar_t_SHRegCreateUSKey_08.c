/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_08.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyW() and SHREGSET_HKCU
 *    BadSink : Create a registry key using SHRegCreateUSKeyW() and SHREGSET_HKLM
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}


void CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_08_bad()
{
    if(staticReturnsTrue())
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



/* good1() uses if(staticReturnsFalse()) instead of if(staticReturnsTrue()) */
static void good1()
{
    if(staticReturnsFalse())
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
    if(staticReturnsTrue())
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

void CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_08_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_08_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_08_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
