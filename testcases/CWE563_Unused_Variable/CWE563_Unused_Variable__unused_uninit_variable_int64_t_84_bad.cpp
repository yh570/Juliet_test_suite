/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_int64_t_84_bad.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_uninit_variable_int64_t_84.h"

namespace CWE563_Unused_Variable__unused_uninit_variable_int64_t_84
{
CWE563_Unused_Variable__unused_uninit_variable_int64_t_84_bad::CWE563_Unused_Variable__unused_uninit_variable_int64_t_84_bad(int64_t dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */
}

CWE563_Unused_Variable__unused_uninit_variable_int64_t_84_bad::~CWE563_Unused_Variable__unused_uninit_variable_int64_t_84_bad()
{
    /* FLAW: Do not use the variable */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}
}
