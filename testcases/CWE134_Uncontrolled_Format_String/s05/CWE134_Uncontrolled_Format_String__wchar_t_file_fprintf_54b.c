/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\A"
#else
#define FILENAME "A"
#endif


/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54c_badSink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54b_badSink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54c_goodG2BSink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54b_goodG2BSink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54c_goodB2GSink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54b_goodB2GSink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_54c_goodB2GSink(data);
}

