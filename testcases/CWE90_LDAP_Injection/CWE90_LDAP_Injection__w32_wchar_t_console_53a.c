/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_console_53a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-53a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")


/* bad function declaration */
void CWE90_LDAP_Injection__w32_wchar_t_console_53b_badSink(wchar_t * data);

void CWE90_LDAP_Injection__w32_wchar_t_console_53_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (256-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(256-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    CWE90_LDAP_Injection__w32_wchar_t_console_53b_badSink(data);
}



/* good function declaration */
void CWE90_LDAP_Injection__w32_wchar_t_console_53b_goodG2BSink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    CWE90_LDAP_Injection__w32_wchar_t_console_53b_goodG2BSink(data);
}

void CWE90_LDAP_Injection__w32_wchar_t_console_53_good()
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
    CWE90_LDAP_Injection__w32_wchar_t_console_53_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE90_LDAP_Injection__w32_wchar_t_console_53_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
