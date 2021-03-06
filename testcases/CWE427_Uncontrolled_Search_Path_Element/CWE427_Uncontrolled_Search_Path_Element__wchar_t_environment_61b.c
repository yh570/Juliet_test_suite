/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_61b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
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


wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_61b_badSource(wchar_t * data)
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
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_61b_goodG2BSource(wchar_t * data)
{
    /* FIX: Set the path as the "system" path */
    wcscat(data, NEW_PATH);
    return data;
}

