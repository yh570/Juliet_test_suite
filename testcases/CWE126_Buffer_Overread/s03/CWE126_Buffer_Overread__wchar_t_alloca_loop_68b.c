/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_loop_68b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE126_Buffer_Overread__wchar_t_alloca_loop_68_badData;
extern wchar_t * CWE126_Buffer_Overread__wchar_t_alloca_loop_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE126_Buffer_Overread__wchar_t_alloca_loop_68b_badSink()
{
    wchar_t * data = CWE126_Buffer_Overread__wchar_t_alloca_loop_68_badData;
    {
        size_t i, destLen;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        destLen = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < destLen; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__wchar_t_alloca_loop_68b_goodG2BSink()
{
    wchar_t * data = CWE126_Buffer_Overread__wchar_t_alloca_loop_68_goodG2BData;
    {
        size_t i, destLen;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        destLen = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < destLen; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

