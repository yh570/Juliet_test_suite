/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int64_t_73b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE476_NULL_Pointer_Dereference__int64_t_73
{


void badSink(list<int64_t *> dataList)
{
    /* copy data out of dataList */
    int64_t * data = dataList.back();
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<int64_t *> dataList)
{
    int64_t * data = dataList.back();
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<int64_t *> dataList)
{
    int64_t * data = dataList.back();
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        printLongLongLine(*data);
    }
    else
    {
        printLine("data is NULL");
    }
}


} /* close namespace */
