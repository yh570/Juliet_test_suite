/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_environment_61b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")


wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_61b_badSource(wchar_t * data)
{
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 256-dataLen-1);
        }
    }
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_61b_goodG2BSource(wchar_t * data)
{
    /* FIX: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    return data;
}

