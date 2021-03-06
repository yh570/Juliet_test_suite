/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_declare_loop_68b.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE127_Buffer_Underread__wchar_t_declare_loop_68_badData;
extern wchar_t * CWE127_Buffer_Underread__wchar_t_declare_loop_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE127_Buffer_Underread__wchar_t_declare_loop_68b_badSink()
{
    wchar_t * data = CWE127_Buffer_Underread__wchar_t_declare_loop_68_badData;
    {
        size_t i;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        for (i = 0; i < 100; i++)
        {
            dest[i] = data[i];
        }
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__wchar_t_declare_loop_68b_goodG2BSink()
{
    wchar_t * data = CWE127_Buffer_Underread__wchar_t_declare_loop_68_goodG2BData;
    {
        size_t i;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        for (i = 0; i < 100; i++)
        {
            dest[i] = data[i];
        }
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

