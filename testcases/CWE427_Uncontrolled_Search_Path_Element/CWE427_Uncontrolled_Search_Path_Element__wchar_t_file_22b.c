/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: file Read input from a file
 * GoodSource: Use a hardcoded path
 * Sink:
 *    BadSink : Set the environment variable
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH L"%SystemRoot%\\system32"
#define PUTENV _wputenv
#else
#define NEW_PATH L"/bin"
#define PUTENV putenv
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif


/* The global variable below is used to drive control flow in the source function */
extern int CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_badGlobal;

wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_badSource(wchar_t * data)
{
    if(CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_badGlobal)
    {
        {
            /* Read input from a file */
            size_t dataLen = wcslen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (250-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgetws(data+dataLen, (int)(250-dataLen), pFile) == NULL)
                    {
                        printLine("fgetws() failed");
                        /* Restore NUL terminator if fgetws fails */
                        data[dataLen] = L'\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    return data;
}



/* The global variables below are used to drive control flow in the source functions. */
extern int CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_goodG2B1Global;
extern int CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_goodG2B1Source(wchar_t * data)
{
    if(CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Set the path as the "system" path */
        wcscat(data, NEW_PATH);
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_goodG2B2Source(wchar_t * data)
{
    if(CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_22_goodG2B2Global)
    {
        /* FIX: Set the path as the "system" path */
        wcscat(data, NEW_PATH);
    }
    return data;
}

