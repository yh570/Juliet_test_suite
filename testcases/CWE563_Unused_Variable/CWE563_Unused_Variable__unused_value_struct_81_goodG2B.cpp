/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_81_goodG2B.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_value_struct_81.h"

namespace CWE563_Unused_Variable__unused_value_struct_81
{

void CWE563_Unused_Variable__unused_value_struct_81_goodG2B::action(twoIntsStruct data) const
{
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.intOne = 1;
    data.intTwo = 1;
    printStructLine(&data);
}

}
