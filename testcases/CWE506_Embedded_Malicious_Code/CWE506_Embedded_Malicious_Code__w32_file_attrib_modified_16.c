/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_file_attrib_modified_16.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: file_attrib_modified
 *    GoodSink: Do not modify the file's last modified time attribute
 *    BadSink : Modify the file's last modified time attribute
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* Note that the FILETIME structure is based on 100-nanosecond intervals.
  It is helpful to define the following symbols when working with file times.
  http://support.microsoft.com/kb/188768 */
#define _SECOND ((INT64)10000000)
#define _MINUTE (60 * _SECOND)
#define _HOUR   (60 * _MINUTE)
#define _DAY    (24 * _HOUR)


void CWE506_Embedded_Malicious_Code__w32_file_attrib_modified_16_bad()
{
    while(1)
    {
        {
            FILETIME ftModified;
            ULONGLONG qwResult;
            HANDLE hFile = INVALID_HANDLE_VALUE;
            do
            {
                hFile = CreateFile(TEXT("badFile.txt"),
                                   GENERIC_READ | GENERIC_WRITE, /* needed for SetFileTime to work properly */
                                   0,
                                   NULL,
                                   CREATE_ALWAYS,
                                   FILE_ATTRIBUTE_NORMAL, NULL);
                if (hFile == INVALID_HANDLE_VALUE)
                {
                    break;
                }
                if (GetFileTime(hFile,
                                NULL,
                                NULL,
                                &ftModified) == 0)
                {
                    break;
                }
                /* adapted from http://support.microsoft.com/kb/188768 */
                qwResult = (((ULONGLONG) ftModified.dwHighDateTime) << 32) + ftModified.dwLowDateTime;
                /* Subtract 10 days from real last modified date */
                qwResult -= 10 * _DAY;
                /* Copy result back into ftModified */
                ftModified.dwLowDateTime  = (DWORD)(qwResult & 0xFFFFFFFF);
                ftModified.dwHighDateTime = (DWORD)(qwResult >> 32);
                /* FLAW: Modify the file's last modified time */
                SetFileTime(hFile,
                            (LPFILETIME)NULL,
                            (LPFILETIME)NULL,
                            &ftModified);
            }
            while (0);
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        {
            HANDLE hFile = CreateFile(TEXT("goodFile.txt"),
                                      GENERIC_READ | GENERIC_WRITE,
                                      0,
                                      NULL,
                                      CREATE_ALWAYS,
                                      FILE_ATTRIBUTE_NORMAL, NULL);
            /* FIX: Do not modify the file's attributes */
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
        break;
    }
}

void CWE506_Embedded_Malicious_Code__w32_file_attrib_modified_16_good()
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
    CWE506_Embedded_Malicious_Code__w32_file_attrib_modified_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE506_Embedded_Malicious_Code__w32_file_attrib_modified_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
