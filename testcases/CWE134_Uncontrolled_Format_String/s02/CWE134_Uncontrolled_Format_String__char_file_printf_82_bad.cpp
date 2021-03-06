/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_printf_82_bad.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_file_printf_82.h"

namespace CWE134_Uncontrolled_Format_String__char_file_printf_82
{

void CWE134_Uncontrolled_Format_String__char_file_printf_82_bad::action(char * data)
{
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

}
