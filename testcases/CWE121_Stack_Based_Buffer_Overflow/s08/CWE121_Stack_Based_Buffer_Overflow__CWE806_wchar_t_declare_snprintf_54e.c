/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_54e.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-54e.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: swprintf
 *    BadSink : Copy data to string using swprintf
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_54e_badSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_54e_goodG2BSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}

