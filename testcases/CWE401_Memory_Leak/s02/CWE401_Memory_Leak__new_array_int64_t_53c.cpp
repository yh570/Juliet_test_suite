/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_int64_t_53c.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_int64_t_53
{


/* bad function declaration */
void badSink_d(int64_t * data);

void badSink_c(int64_t * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(int64_t * data);

void goodG2BSink_c(int64_t * data)
{
    goodG2BSink_d(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_d(int64_t * data);

void goodB2GSink_c(int64_t * data)
{
    goodB2GSink_d(data);
}


} /* close namespace */
