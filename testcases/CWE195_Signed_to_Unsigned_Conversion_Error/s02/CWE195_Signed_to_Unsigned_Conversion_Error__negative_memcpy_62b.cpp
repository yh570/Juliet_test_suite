/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_62b.cpp
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_62
{


void badSource(int &data)
{
    /* FLAW: Use a negative number */
    data = -1;
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(int &data)
{
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
}


} /* close namespace */
