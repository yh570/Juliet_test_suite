/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_snprintf_74b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

using namespace std;

namespace CWE134_Uncontrolled_Format_String__char_environment_snprintf_74
{


void badSink(map<int, char *> dataMap)
{
    /* copy data out of dataMap */
    char * data = dataMap[2];
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, char *> dataMap)
{
    char * data = dataMap[2];
    {
        char dest[100] = "";
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, char *> dataMap)
{
    char * data = dataMap[2];
    {
        char dest[100] = "";
        /* FIX: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
}


} /* close namespace */
