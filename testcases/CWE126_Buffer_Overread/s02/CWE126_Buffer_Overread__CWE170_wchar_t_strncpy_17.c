/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_17.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: strncpy
 *    GoodSink: Copy a string using wcsncpy() with explicit null termination
 *    BadSink : Copy a string using wcsncpy() without explicit null termination
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 99);
            /* FLAW: do not explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 99);
            dest[99] = L'\0'; /* FIX: Explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
}

void CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_17_good()
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
    CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
