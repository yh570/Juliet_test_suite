/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_snprintf_04.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snprintf with data as the third argument
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */


void CWE134_Uncontrolled_Format_String__char_environment_snprintf_04_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(STATIC_CONST_TRUE)
    {
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
    if(STATIC_CONST_TRUE)
    {
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodB2G1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(STATIC_CONST_TRUE)
    {
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
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(STATIC_CONST_TRUE)
    {
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
    if(STATIC_CONST_TRUE)
    {
        {
            char dest[100] = "";
            /* FIX: Specify the format disallowing a format string vulnerability */
            SNPRINTF(dest, 100-1, "%s", data);
            printLine(dest);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodG2B1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(STATIC_CONST_TRUE)
    {
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(STATIC_CONST_TRUE)
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(STATIC_CONST_TRUE)
    {
        {
            char dest[100] = "";
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            SNPRINTF(dest, 100-1, data);
            printLine(dest);
        }
    }
}

void CWE134_Uncontrolled_Format_String__char_environment_snprintf_04_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE134_Uncontrolled_Format_String__char_environment_snprintf_04_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_environment_snprintf_04_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
