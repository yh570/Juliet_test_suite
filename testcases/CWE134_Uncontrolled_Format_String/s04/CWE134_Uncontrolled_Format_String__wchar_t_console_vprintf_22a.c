/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vwprintf with a format string
 *    BadSink : vwprintf without a format string
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


/* The global variable below is used to drive control flow in the sink function */
int CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_badGlobal = 0;

void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_badVaSink(wchar_t * data, ...);

void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_badGlobal = 1; /* true */
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_badVaSink(data, data);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G1Global = 0;
int CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G2Global = 0;
int CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodG2BGlobal = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G1_vasink(wchar_t * data, ...);

static void goodB2G1()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G1Global = 0; /* false */
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G1_vasink(data, data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G2_vasink(wchar_t * data, ...);

static void goodB2G2()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G2Global = 1; /* true */
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodB2G2_vasink(data, data);
}

/* goodG2B() - use goodsource and badsink */
void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodG2BVaSink(wchar_t * data, ...);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Use a fixed string that does not contain a format specifier */
    wcscpy(data, L"fixedstringtest");
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodG2BGlobal = 1; /* true */
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_goodG2BVaSink(data, data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
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
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__wchar_t_console_vprintf_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
