/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_TwoIntsClass_73b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE401_Memory_Leak__new_array_TwoIntsClass_73
{


void badSink(list<TwoIntsClass *> dataList)
{
    /* copy data out of dataList */
    TwoIntsClass * data = dataList.back();
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<TwoIntsClass *> dataList)
{
    TwoIntsClass * data = dataList.back();
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<TwoIntsClass *> dataList)
{
    TwoIntsClass * data = dataList.back();
    /* FIX: Deallocate memory */
    delete[] data;
}


} /* close namespace */
