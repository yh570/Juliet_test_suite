/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_09.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegOpenKeyEx
 *    GoodSink: Open a registry key using RegOpenKeyExA() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using RegOpenKeyExA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )


void CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegOpenKeyExA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegOpenKeyExA(
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
}



/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegOpenKeyExA() with HKEY_CURRENT_USER */
            if (RegOpenKeyExA(
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
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegOpenKeyExA() with HKEY_CURRENT_USER */
            if (RegOpenKeyExA(
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
}

void CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_09_good()
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
    CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
