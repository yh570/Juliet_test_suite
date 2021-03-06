/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: snprintf
 *    BadSink : Copy data to string using snprintf
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52c_badSink(char * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52b_badSink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52c_badSink(data);
}



/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52c_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52b_goodG2BSink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_52c_goodG2BSink(data);
}

