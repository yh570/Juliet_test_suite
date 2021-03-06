/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_72b.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_value_struct_72
{


void badSink(vector<twoIntsStruct> dataVector)
{
    /* copy data out of dataVector */
    twoIntsStruct data = dataVector[2];
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.intOne = 1;
    data.intTwo = 1;
    printStructLine(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<twoIntsStruct> dataVector)
{
    twoIntsStruct data = dataVector[2];
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.intOne = 1;
    data.intTwo = 1;
    printStructLine(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<twoIntsStruct> dataVector)
{
    twoIntsStruct data = dataVector[2];
    /* FIX: Use data without over-writing its value */
    printStructLine(&data);
}


} /* close namespace */
