/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_64a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
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


/* bad function declaration */
void CWE90_LDAP_Injection__w32_char_environment_64b_badSink(void * dataVoidPtr);

void CWE90_LDAP_Injection__w32_char_environment_64_bad()
{
    char * data;
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
    CWE90_LDAP_Injection__w32_char_environment_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE90_LDAP_Injection__w32_char_environment_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    char * data;
    char dataBuffer[256] = "";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    CWE90_LDAP_Injection__w32_char_environment_64b_goodG2BSink(&data);
}

void CWE90_LDAP_Injection__w32_char_environment_64_good()
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
    CWE90_LDAP_Injection__w32_char_environment_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE90_LDAP_Injection__w32_char_environment_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
