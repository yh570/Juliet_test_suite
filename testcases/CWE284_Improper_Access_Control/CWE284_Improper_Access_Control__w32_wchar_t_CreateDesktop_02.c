/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_wchar_t_CreateDesktop_02.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateDesktop
 *    GoodSink: Create a desktop using CreateDesktopW() without excessive privileges
 *    BadSink : Create a desktop using CreateDesktopW() with excessive privileges
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )


void CWE284_Improper_Access_Control__w32_wchar_t_CreateDesktop_02_bad()
{
    if(1)
    {
        {
            HDESK hDesk;
            wchar_t * desktopName = L"DesktopExample";
            /* FLAW: Call CreateDesktopW() with GENERIC_ALL as the 5th parameter */
            hDesk = CreateDesktopW(
                        desktopName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_ALL,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
    }
}



/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            HDESK hDesk;
            wchar_t * desktopName = L"DesktopExample";
            /* FIX: Call CreateDesktopW() without GENERIC_READ as the 5th parameter to limit access */
            hDesk = CreateDesktopW(
                        desktopName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_READ,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            HDESK hDesk;
            wchar_t * desktopName = L"DesktopExample";
            /* FIX: Call CreateDesktopW() without GENERIC_READ as the 5th parameter to limit access */
            hDesk = CreateDesktopW(
                        desktopName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_READ,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
    }
}

void CWE284_Improper_Access_Control__w32_wchar_t_CreateDesktop_02_good()
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
    CWE284_Improper_Access_Control__w32_wchar_t_CreateDesktop_02_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_wchar_t_CreateDesktop_02_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
