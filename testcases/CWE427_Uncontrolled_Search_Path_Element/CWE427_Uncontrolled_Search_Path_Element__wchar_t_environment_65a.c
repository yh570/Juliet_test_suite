/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
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


/* bad function declaration */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b_badSink(wchar_t * data);

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65_bad()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b_badSink;
    wchar_t dataBuffer[250] = L"PATH=";
    data = dataBuffer;
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
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b_goodG2BSink;
    wchar_t dataBuffer[250] = L"PATH=";
    data = dataBuffer;
    /* FIX: Set the path as the "system" path */
    wcscat(data, NEW_PATH);
    funcPtr(data);
}

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65_good()
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
