/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_snprintf_65b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: swprintf
 *    BadSink : Copy data to string using swprintf
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif


void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_snprintf_65b_badSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_snprintf_65b_goodG2BSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}

