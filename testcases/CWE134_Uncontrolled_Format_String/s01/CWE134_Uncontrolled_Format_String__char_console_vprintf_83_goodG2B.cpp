/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vprintf_83_goodG2B.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_console_vprintf_83.h"

namespace CWE134_Uncontrolled_Format_String__char_console_vprintf_83
{
CWE134_Uncontrolled_Format_String__char_console_vprintf_83_goodG2B::CWE134_Uncontrolled_Format_String__char_console_vprintf_83_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
}

static void goodG2BVaSink(char * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vprintf(data, args);
        va_end(args);
    }
}

CWE134_Uncontrolled_Format_String__char_console_vprintf_83_goodG2B::~CWE134_Uncontrolled_Format_String__char_console_vprintf_83_goodG2B()
{
    goodG2BVaSink(data, data);
}
}
