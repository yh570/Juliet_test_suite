/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_char_82_goodB2G.cpp
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_init_variable_char_82.h"

namespace CWE563_Unused_Variable__unused_init_variable_char_82
{

void CWE563_Unused_Variable__unused_init_variable_char_82_goodB2G::action(char data)
{
    /* FIX: Use data */
    printHexCharLine(data);
}

}
