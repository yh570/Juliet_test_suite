/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_01.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: memcpy
 *    GoodSink: Copy a string using memcpy with explicit null termination
 *    BadSink : Copy a string using memcpy without explicit null termination
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_01_bad()
{
    {
        wchar_t data[150], dest[100];
        /* Initialize data */
        wmemset(data, L'A', 149);
        data[149] = L'\0';
        memcpy(dest, data, 99*sizeof(wchar_t));
        /* FLAW: do not explicitly null terminate dest after the use of memcpy */
        printWLine(dest);
    }
}



static void good1()
{
    {
        wchar_t data[150], dest[100];
        /* Initialize data */
        wmemset(data, L'A', 149);
        data[149] = L'\0';
        memcpy(dest, data, 99*sizeof(wchar_t));
        dest[99] = L'\0'; /* FIX: null terminate dest */
        printWLine(dest);
    }
}

void CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_01_good()
{
    good1();
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
    CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
