/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_vprintf_22a.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\A"
#else
#define FILENAME "A"
#endif


/* The global variable below is used to drive control flow in the sink function */
int CWE134_Uncontrolled_Format_String__char_file_vprintf_22_badGlobal = 0;

void CWE134_Uncontrolled_Format_String__char_file_vprintf_22_badVaSink(char * data, ...);

void CWE134_Uncontrolled_Format_String__char_file_vprintf_22_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_badGlobal = 1; /* true */
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_badVaSink(data, data);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G1Global = 0;
int CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G2Global = 0;
int CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodG2BGlobal = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G1_vasink(char * data, ...);

static void goodB2G1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G1Global = 0; /* false */
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G1_vasink(data, data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G2_vasink(char * data, ...);

static void goodB2G2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G2Global = 1; /* true */
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodB2G2_vasink(data, data);
}

/* goodG2B() - use goodsource and badsink */
void CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodG2BVaSink(char * data, ...);

static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodG2BGlobal = 1; /* true */
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_goodG2BVaSink(data, data);
}

void CWE134_Uncontrolled_Format_String__char_file_vprintf_22_good()
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
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_file_vprintf_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
