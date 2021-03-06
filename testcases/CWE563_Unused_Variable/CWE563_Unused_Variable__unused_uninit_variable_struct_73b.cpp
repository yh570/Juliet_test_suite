/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_struct_73b.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_uninit_variable_struct_73
{


void badSink(list<twoIntsStruct> dataList)
{
    /* copy data out of dataList */
    twoIntsStruct data = dataList.back();
    /* FLAW: Do not use the variable */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}



/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<twoIntsStruct> dataList)
{
    twoIntsStruct data = dataList.back();
    /* FIX: Initialize then use data */
    data.intOne = 0;
    data.intTwo = 0;
    printStructLine(&data);
}


} /* close namespace */
