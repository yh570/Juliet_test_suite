/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoIntsStruct_53c.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_53
{


/* bad function declaration */
void badSink_d(struct _twoIntsStruct * data);

void badSink_c(struct _twoIntsStruct * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(struct _twoIntsStruct * data);

void goodG2BSink_c(struct _twoIntsStruct * data)
{
    goodG2BSink_d(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_d(struct _twoIntsStruct * data);

void goodB2GSink_c(struct _twoIntsStruct * data)
{
    goodB2GSink_d(data);
}


} /* close namespace */
