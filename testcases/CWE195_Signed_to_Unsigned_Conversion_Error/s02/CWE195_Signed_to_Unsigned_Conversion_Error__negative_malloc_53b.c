/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53c_badSink(int data);

void CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53b_badSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53c_badSink(data);
}



/* good function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53c_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53b_goodG2BSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_malloc_53c_goodG2BSink(data);
}

