/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_snprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
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

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif


/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_file_snprintf_54c_badSink(char * data);

void CWE134_Uncontrolled_Format_String__char_file_snprintf_54b_badSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_file_snprintf_54c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_file_snprintf_54c_goodG2BSink(char * data);

void CWE134_Uncontrolled_Format_String__char_file_snprintf_54b_goodG2BSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_file_snprintf_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_file_snprintf_54c_goodB2GSink(char * data);

void CWE134_Uncontrolled_Format_String__char_file_snprintf_54b_goodB2GSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_file_snprintf_54c_goodB2GSink(data);
}

