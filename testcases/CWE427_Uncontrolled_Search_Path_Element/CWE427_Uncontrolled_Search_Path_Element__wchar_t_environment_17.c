/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_17.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sink:
 *    BadSink : Set the environment variable
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH L"%SystemRoot%\\system32"
#define PUTENV _wputenv
#else
#define NEW_PATH L"/bin"
#define PUTENV putenv
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif


void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_17_bad()
{
    int i;
    wchar_t * data;
    wchar_t dataBuffer[250] = L"PATH=";
    data = dataBuffer;
    for(i = 0; i < 1; i++)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = wcslen(data);
            wchar_t * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                wcsncat(data+dataLen, environment, 250-dataLen-1);
            }
        }
    }
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}



/* goodG2B() - use goodsource and badsink by changing the conditions on the for statements */
static void goodG2B()
{
    int h;
    wchar_t * data;
    wchar_t dataBuffer[250] = L"PATH=";
    data = dataBuffer;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Set the path as the "system" path */
        wcscat(data, NEW_PATH);
    }
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_17_good()
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
