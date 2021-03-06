/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_console_68b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: console Read input from the console
 * GoodSource: Use a hardcoded path
 * Sink:
 *    BadSink : Set the environment variable
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

extern char * CWE427_Uncontrolled_Search_Path_Element__char_console_68_badData;
extern char * CWE427_Uncontrolled_Search_Path_Element__char_console_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE427_Uncontrolled_Search_Path_Element__char_console_68b_badSink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_console_68_badData;
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__char_console_68b_goodG2BSink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_console_68_goodG2BData;
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

