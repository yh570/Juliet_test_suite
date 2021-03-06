/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63a.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif


/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63b_badSink(wchar_t * * dataPtr);

void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63b_goodG2BSink(wchar_t * * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63b_goodB2GSink(wchar_t * * data);

static void goodB2G()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63b_goodB2GSink(&data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63_good()
{
    goodG2B();
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_63_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
