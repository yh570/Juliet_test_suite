/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memmove_61a.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memmove_61b_badSource(wchar_t * data);

void CWE126_Buffer_Overread__malloc_wchar_t_memmove_61_bad()
{
    wchar_t * data;
    data = NULL;
    data = CWE126_Buffer_Overread__malloc_wchar_t_memmove_61b_badSource(data);
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memmove_61b_goodG2BSource(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    data = CWE126_Buffer_Overread__malloc_wchar_t_memmove_61b_goodG2BSource(data);
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}

void CWE126_Buffer_Overread__malloc_wchar_t_memmove_61_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE126_Buffer_Overread__malloc_wchar_t_memmove_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__malloc_wchar_t_memmove_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
