/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsStruct_54d.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_twointsStruct_54
{


/* bad function declaration */
void badSink_e(twoIntsStruct * data);

void badSink_d(twoIntsStruct * data)
{
    badSink_e(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_e(twoIntsStruct * data);

void goodG2BSink_d(twoIntsStruct * data)
{
    goodG2BSink_e(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_e(twoIntsStruct * data);

void goodB2GSink_d(twoIntsStruct * data)
{
    goodB2GSink_e(data);
}


} /* close namespace */
