/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_char_CreateWindowStation_12.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateWindowStation
 *    GoodSink: Create a windows station using CreateWindowStationA() without excessive privileges
 *    BadSink : Create a windows station using CreateWindowStationA() with excessive privileges
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )


void CWE284_Improper_Access_Control__w32_char_CreateWindowStation_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            HWINSTA hWinStation;
            char * wStationName = "WindowsStationExample";
            /* FLAW: Call CreateWindowStationA() with GENERIC_ALL as the 3rd parameter */
            hWinStation = CreateWindowStationA(
                              wStationName,
                              0,
                              GENERIC_ALL,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
    else
    {
        {
            HWINSTA hWinStation;
            char * wStationName = "WindowsStationExample";
            /* FIX: Call CreateWindowStationA() without GENERIC_READ as the 3rd parameter to limit access */
            hWinStation = CreateWindowStationA(
                              wStationName,
                              0,
                              GENERIC_READ,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
}



/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            HWINSTA hWinStation;
            char * wStationName = "WindowsStationExample";
            /* FIX: Call CreateWindowStationA() without GENERIC_READ as the 3rd parameter to limit access */
            hWinStation = CreateWindowStationA(
                              wStationName,
                              0,
                              GENERIC_READ,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
    else
    {
        {
            HWINSTA hWinStation;
            char * wStationName = "WindowsStationExample";
            /* FIX: Call CreateWindowStationA() without GENERIC_READ as the 3rd parameter to limit access */
            hWinStation = CreateWindowStationA(
                              wStationName,
                              0,
                              GENERIC_READ,
                              NULL);
            if (hWinStation == NULL)
            {
                printLine("Windows station could not be created");
            }
            else
            {
                printLine("Windows Station created successfully");
                CloseWindowStation(hWinStation);
            }
        }
    }
}

void CWE284_Improper_Access_Control__w32_char_CreateWindowStation_12_good()
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
    CWE284_Improper_Access_Control__w32_char_CreateWindowStation_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_char_CreateWindowStation_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
