/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54c.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54d_badSink(int data);

void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54c_badSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54d_badSink(data);
}



/* good function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54d_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54c_goodG2BSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_54d_goodG2BSink(data);
}

