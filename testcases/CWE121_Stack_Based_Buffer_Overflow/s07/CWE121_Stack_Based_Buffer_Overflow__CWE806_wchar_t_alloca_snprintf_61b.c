/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_snprintf_61b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: snprintf
 *    BadSink : Copy data to string using snprintf
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF snprintf
#endif


wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_snprintf_61b_badSource(wchar_t * data)
{
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_snprintf_61b_goodG2BSource(wchar_t * data)
{
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
    return data;
}

