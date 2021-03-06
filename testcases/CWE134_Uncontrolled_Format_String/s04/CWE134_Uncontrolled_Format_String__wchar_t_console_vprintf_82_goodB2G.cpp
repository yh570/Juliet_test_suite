/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_82_goodB2G.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vwprintf with a format string
 *    BadSink : vwprintf without a format string
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_82.h"

namespace CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_82
{

static void goodB2GVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vwprintf(L"%s", args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_82_goodB2G::action(wchar_t * data)
{
    goodB2GVaSink(data, data);
}

}
