/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53c_badSink(wchar_t * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53b_badSink(wchar_t * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53c_badSink(data);
}



/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53c_goodG2BSink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53b_goodG2BSink(wchar_t * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_53c_goodG2BSink(data);
}

