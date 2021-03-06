/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_alloca_memcpy_52b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE126_Buffer_Overread__char_alloca_memcpy_52c_badSink(char * data);

void CWE126_Buffer_Overread__char_alloca_memcpy_52b_badSink(char * data)
{
    CWE126_Buffer_Overread__char_alloca_memcpy_52c_badSink(data);
}



/* good function declaration */
void CWE126_Buffer_Overread__char_alloca_memcpy_52c_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__char_alloca_memcpy_52b_goodG2BSink(char * data)
{
    CWE126_Buffer_Overread__char_alloca_memcpy_52c_goodG2BSink(data);
}

