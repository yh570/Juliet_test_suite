/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_environment_61a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-61a.tmpl.c
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


/* bad function declaration */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_61b_badSource(wchar_t * data);

void CWE90_LDAP_Injection__w32_wchar_t_environment_61_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    data = CWE90_LDAP_Injection__w32_wchar_t_environment_61b_badSource(data);
    {
        LDAP* pLdapConnection = NULL;
        ULONG connectSuccess = 0L;
        ULONG searchSuccess = 0L;
        LDAPMessage *pMessage = NULL;
        wchar_t filter[256];
        /* POTENTIAL FLAW: data concatenated into LDAP search, which could result in LDAP Injection*/
        _snwprintf(filter, 256-1, L"(cn=%s)", data);
        pLdapConnection = ldap_initW(L"localhost", LDAP_PORT);
        if (pLdapConnection == NULL)
        {
            printLine("Initialization failed");
            exit(1);
        }
        connectSuccess = ldap_connect(pLdapConnection, NULL);
        if (connectSuccess != LDAP_SUCCESS)
        {
            printLine("Connection failed");
            exit(1);
        }
        searchSuccess = ldap_search_ext_sW(
                            pLdapConnection,
                            L"base",
                            LDAP_SCOPE_SUBTREE,
                            filter,
                            NULL,
                            0,
                            NULL,
                            NULL,
                            LDAP_NO_LIMIT,
                            LDAP_NO_LIMIT,
                            &pMessage);
        if (searchSuccess != LDAP_SUCCESS)
        {
            printLine("Search failed");
            if (pMessage != NULL)
            {
                ldap_msgfree(pMessage);
            }
            exit(1);
        }
        /* Typically you would do something with the search results, but this is a test case and we can ignore them */
        /* Free the results to avoid incidentals */
        if (pMessage != NULL)
        {
            ldap_msgfree(pMessage);
        }
        /* Close the connection */
        ldap_unbind(pLdapConnection);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_61b_goodG2BSource(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    data = CWE90_LDAP_Injection__w32_wchar_t_environment_61b_goodG2BSource(data);
    {
        LDAP* pLdapConnection = NULL;
        ULONG connectSuccess = 0L;
        ULONG searchSuccess = 0L;
        LDAPMessage *pMessage = NULL;
        wchar_t filter[256];
        /* POTENTIAL FLAW: data concatenated into LDAP search, which could result in LDAP Injection*/
        _snwprintf(filter, 256-1, L"(cn=%s)", data);
        pLdapConnection = ldap_initW(L"localhost", LDAP_PORT);
        if (pLdapConnection == NULL)
        {
            printLine("Initialization failed");
            exit(1);
        }
        connectSuccess = ldap_connect(pLdapConnection, NULL);
        if (connectSuccess != LDAP_SUCCESS)
        {
            printLine("Connection failed");
            exit(1);
        }
        searchSuccess = ldap_search_ext_sW(
                            pLdapConnection,
                            L"base",
                            LDAP_SCOPE_SUBTREE,
                            filter,
                            NULL,
                            0,
                            NULL,
                            NULL,
                            LDAP_NO_LIMIT,
                            LDAP_NO_LIMIT,
                            &pMessage);
        if (searchSuccess != LDAP_SUCCESS)
        {
            printLine("Search failed");
            if (pMessage != NULL)
            {
                ldap_msgfree(pMessage);
            }
            exit(1);
        }
        /* Typically you would do something with the search results, but this is a test case and we can ignore them */
        /* Free the results to avoid incidentals */
        if (pMessage != NULL)
        {
            ldap_msgfree(pMessage);
        }
        /* Close the connection */
        ldap_unbind(pLdapConnection);
    }
}

void CWE90_LDAP_Injection__w32_wchar_t_environment_61_good()
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
    CWE90_LDAP_Injection__w32_wchar_t_environment_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE90_LDAP_Injection__w32_wchar_t_environment_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
