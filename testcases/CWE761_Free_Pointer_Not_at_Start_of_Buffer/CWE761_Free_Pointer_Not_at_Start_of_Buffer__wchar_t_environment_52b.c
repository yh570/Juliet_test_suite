/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: environment Read input from an environment variable
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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


/* bad function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52c_badSink(wchar_t * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52b_badSink(wchar_t * data)
{
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52c_badSink(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52c_goodB2GSink(wchar_t * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52b_goodB2GSink(wchar_t * data)
{
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_environment_52c_goodB2GSink(data);
}

