/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_alloca_loop_63b.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE124_Buffer_Underwrite__wchar_t_alloca_loop_63b_badSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE124_Buffer_Underwrite__wchar_t_alloca_loop_63b_goodG2BSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = L'\0';
        printWLine(data);
    }
}

