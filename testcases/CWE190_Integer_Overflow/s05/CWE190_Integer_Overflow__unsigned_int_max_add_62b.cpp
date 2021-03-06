/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_add_62b.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE190_Integer_Overflow__unsigned_int_max_add_62
{


void badSource(unsigned int &data)
{
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(unsigned int &data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(unsigned int &data)
{
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
}


} /* close namespace */
