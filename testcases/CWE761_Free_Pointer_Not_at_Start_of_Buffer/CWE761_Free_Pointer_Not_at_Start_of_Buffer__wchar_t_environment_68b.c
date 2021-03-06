/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: environment Read input from an environment variable
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#define SEARCH_CHAR L'S'

extern wchar_t * CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68_badDataForBadSink;

extern wchar_t * CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68_badDataForGoodSink;


void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68b_badSink()
{
    wchar_t * data = CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68_badDataForBadSink;
    /* FLAW: We are incrementing the pointer in the loop - this will cause us to free the
     * memory block not at the start of the buffer */
    for (; *data != L'\0'; data++)
    {
        if (*data == SEARCH_CHAR)
        {
            printLine("We have a match!");
            break;
        }
    }
    free(data);
}



void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68b_goodB2GSink()
{
    wchar_t * data = CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_68_badDataForGoodSink;
    {
        size_t i;
        /* FIX: Use a loop variable to traverse through the string pointed to by data */
        for (i=0; i < wcslen(data); i++)
        {
            if (data[i] == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

