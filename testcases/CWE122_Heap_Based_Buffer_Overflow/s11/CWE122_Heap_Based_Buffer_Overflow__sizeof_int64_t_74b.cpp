/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_74b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_74
{


void badSink(map<int, int64_t *> dataMap)
{
    /* copy data out of dataMap */
    int64_t * data = dataMap[2];
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, int64_t *> dataMap)
{
    int64_t * data = dataMap[2];
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}


} /* close namespace */
