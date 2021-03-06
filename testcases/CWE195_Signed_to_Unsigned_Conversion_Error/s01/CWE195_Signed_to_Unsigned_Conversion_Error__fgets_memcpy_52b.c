/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52c_badSink(int data);

void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52b_badSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52c_badSink(data);
}



/* good function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52c_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52b_goodG2BSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_52c_goodG2BSink(data);
}

