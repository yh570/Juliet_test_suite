/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-65b.tmpl.c
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


void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b_badSink(wchar_t * data)
{
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_65b_goodG2BSink(wchar_t * data)
{
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

