/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_fscanf_multiply_62b.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE191_Integer_Underflow__short_fscanf_multiply_62
{


void badSource(short &data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hd", &data);
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(short &data)
{
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(short &data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hd", &data);
}


} /* close namespace */
