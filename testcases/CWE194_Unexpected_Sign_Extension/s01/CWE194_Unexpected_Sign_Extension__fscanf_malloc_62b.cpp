/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_malloc_62b.cpp
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sinks: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE194_Unexpected_Sign_Extension__fscanf_malloc_62
{


void badSource(short &data)
{
    /* FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%hd", &data);
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(short &data)
{
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
}


} /* close namespace */
