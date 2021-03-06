/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_81_goodG2B.cpp
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__int_zero_modulo_81.h"

namespace CWE369_Divide_by_Zero__int_zero_modulo_81
{

void CWE369_Divide_by_Zero__int_zero_modulo_81_goodG2B::action(int data) const
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

}
