/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int_73b.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_value_int_73
{


void badSink(list<int> dataList)
{
    /* copy data out of dataList */
    int data = dataList.back();
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = 10;
    printIntLine(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<int> dataList)
{
    int data = dataList.back();
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = 10;
    printIntLine(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<int> dataList)
{
    int data = dataList.back();
    /* FIX: Use data without over-writing its value */
    printIntLine(data);
}


} /* close namespace */
