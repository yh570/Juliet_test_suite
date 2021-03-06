/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_81_goodG2B.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vwprintf with a format string
 *    BadSink : vwprintf without a format string
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_81.h"

namespace CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_81
{

static void goodG2BVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vwprintf(data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_81_goodG2B::action(wchar_t * data) const
{
    goodG2BVaSink(data, data);
}

}
