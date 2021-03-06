/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_large_62b.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE126_Buffer_Overread__CWE129_large_62
{


void badSource(int &data)
{
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(int &data)
{
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(int &data)
{
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
}


} /* close namespace */
