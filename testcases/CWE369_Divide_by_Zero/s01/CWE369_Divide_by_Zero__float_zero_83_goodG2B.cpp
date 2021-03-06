/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_83_goodG2B.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__float_zero_83.h"

namespace CWE369_Divide_by_Zero__float_zero_83
{
CWE369_Divide_by_Zero__float_zero_83_goodG2B::CWE369_Divide_by_Zero__float_zero_83_goodG2B(float dataCopy)
{
    data = dataCopy;
    /* FIX: Use a hardcoded number that won't a divide by zero */
    data = 2.0F;
}

CWE369_Divide_by_Zero__float_zero_83_goodG2B::~CWE369_Divide_by_Zero__float_zero_83_goodG2B()
{
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}
}
