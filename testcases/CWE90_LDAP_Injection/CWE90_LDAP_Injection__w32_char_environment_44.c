/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_44.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")


static void badSink(char * data)
{
    {
        LDAP* pLdapConnection = NULL;
        ULONG connectSuccess = 0L;
        ULONG searchSuccess = 0L;
        LDAPMessage *pMessage = NULL;
        char filter[256];
        /* POTENTIAL FLAW: data concatenated into LDAP search, which could result in LDAP Injection*/
        _snprintf(filter, 256-1, "(cn=%s)", data);
        pLdapConnection = ldap_initA("localhost", LDAP_PORT);
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
        searchSuccess = ldap_search_ext_sA(
                            pLdapConnection,
                            "base",
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

void CWE90_LDAP_Injection__w32_char_environment_44_bad()
{
    char * data;
    /* define a function pointer */
    void (*funcPtr) (char *) = badSink;
    char dataBuffer[256] = "";
    data = dataBuffer;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            strncat(data+dataLen, environment, 256-dataLen-1);
        }
    }
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(char * data)
{
    {
        LDAP* pLdapConnection = NULL;
        ULONG connectSuccess = 0L;
        ULONG searchSuccess = 0L;
        LDAPMessage *pMessage = NULL;
        char filter[256];
        /* POTENTIAL FLAW: data concatenated into LDAP search, which could result in LDAP Injection*/
        _snprintf(filter, 256-1, "(cn=%s)", data);
        pLdapConnection = ldap_initA("localhost", LDAP_PORT);
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
        searchSuccess = ldap_search_ext_sA(
                            pLdapConnection,
                            "base",
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

static void goodG2B()
{
    char * data;
    void (*funcPtr) (char *) = goodG2BSink;
    char dataBuffer[256] = "";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    funcPtr(data);
}

void CWE90_LDAP_Injection__w32_char_environment_44_good()
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
    CWE90_LDAP_Injection__w32_char_environment_44_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE90_LDAP_Injection__w32_char_environment_44_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
