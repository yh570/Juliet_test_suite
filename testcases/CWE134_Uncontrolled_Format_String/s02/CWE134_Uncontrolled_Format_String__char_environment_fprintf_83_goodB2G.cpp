/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_fprintf_83_goodB2G.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fprintf with "%s" as the second argument and data as the third
 *    BadSink : fprintf with data as the second argument
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_environment_fprintf_83.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

namespace CWE134_Uncontrolled_Format_String__char_environment_fprintf_83
{
CWE134_Uncontrolled_Format_String__char_environment_fprintf_83_goodB2G::CWE134_Uncontrolled_Format_String__char_environment_fprintf_83_goodB2G(char * dataCopy)
{
    data = dataCopy;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            strncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
}

CWE134_Uncontrolled_Format_String__char_environment_fprintf_83_goodB2G::~CWE134_Uncontrolled_Format_String__char_environment_fprintf_83_goodB2G()
{
    /* FIX: Specify the format disallowing a format string vulnerability */
    fprintf(stdout, "%s\n", data);
}
}
