/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int64_t_72b.cpp
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_init_variable_int64_t_72
{


void badSink(vector<int64_t> dataVector)
{
    /* copy data out of dataVector */
    int64_t data = dataVector[2];
    /* FLAW: Do not use the variable */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}



/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<int64_t> dataVector)
{
    int64_t data = dataVector[2];
    /* FIX: Use data */
    printLongLongLine(data);
}


} /* close namespace */
