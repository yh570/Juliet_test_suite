/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vprintf_67a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType
{
    char * structFirst;
} CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType;


/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_67b_badSink(CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType myStruct);

void CWE134_Uncontrolled_Format_String__char_console_vprintf_67_bad()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType myStruct;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = strlen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgets() */
                dataLen = strlen(data);
                if (dataLen > 0 && data[dataLen-1] == '\n')
                {
                    data[dataLen-1] = '\0';
                }
            }
            else
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                data[dataLen] = '\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_67b_goodG2BSink(CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType myStruct);

static void goodG2B()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType myStruct;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    myStruct.structFirst = data;
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_67b_goodB2GSink(CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType myStruct);

static void goodB2G()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67_structType myStruct;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = strlen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgets() */
                dataLen = strlen(data);
                if (dataLen > 0 && data[dataLen-1] == '\n')
                {
                    data[dataLen-1] = '\0';
                }
            }
            else
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                data[dataLen] = '\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67b_goodB2GSink(myStruct);
}

void CWE134_Uncontrolled_Format_String__char_console_vprintf_67_good()
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
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_console_vprintf_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
