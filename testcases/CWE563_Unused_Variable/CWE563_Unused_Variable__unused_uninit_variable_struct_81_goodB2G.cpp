/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_struct_81_goodB2G.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_uninit_variable_struct_81.h"

namespace CWE563_Unused_Variable__unused_uninit_variable_struct_81
{

void CWE563_Unused_Variable__unused_uninit_variable_struct_81_goodB2G::action(twoIntsStruct data) const
{
    /* FIX: Initialize then use data */
    data.intOne = 0;
    data.intTwo = 0;
    printStructLine(&data);
}

}
