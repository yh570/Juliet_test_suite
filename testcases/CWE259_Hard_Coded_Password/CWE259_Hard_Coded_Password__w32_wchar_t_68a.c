/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_68a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"ABCD1234!"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

wchar_t * CWE259_Hard_Coded_Password__w32_wchar_t_68_badData;
wchar_t * CWE259_Hard_Coded_Password__w32_wchar_t_68_goodG2BData;


/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_wchar_t_68b_badSink();

void CWE259_Hard_Coded_Password__w32_wchar_t_68_bad()
{
    wchar_t * password;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    wcscpy(password, PASSWORD);
    CWE259_Hard_Coded_Password__w32_wchar_t_68_badData = password;
    CWE259_Hard_Coded_Password__w32_wchar_t_68b_badSink();
}



/* good function declarations */
void CWE259_Hard_Coded_Password__w32_wchar_t_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * password;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    {
        size_t passwordLen = 0;
        /* FIX: Read the password from the console */
        if (fgetws(password, 100, stdin) == NULL)
        {
            printLine("fgetws() failed");
            /* Restore NUL terminator if fgetws fails */
            password[0] = L'\0';
        }
        /* Remove the carriage return from the string that is inserted by fgetws() */
        passwordLen = wcslen(password);
        if (passwordLen > 0)
        {
            password[passwordLen-1] = L'\0';
        }
    }
    CWE259_Hard_Coded_Password__w32_wchar_t_68_goodG2BData = password;
    CWE259_Hard_Coded_Password__w32_wchar_t_68b_goodG2BSink();
}

void CWE259_Hard_Coded_Password__w32_wchar_t_68_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE259_Hard_Coded_Password__w32_wchar_t_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE259_Hard_Coded_Password__w32_wchar_t_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
