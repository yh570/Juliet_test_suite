/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_divide_83_goodB2G.cpp
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__int_zero_divide_83.h"

namespace CWE369_Divide_by_Zero__int_zero_divide_83
{
CWE369_Divide_by_Zero__int_zero_divide_83_goodB2G::CWE369_Divide_by_Zero__int_zero_divide_83_goodB2G(int dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0;
}

CWE369_Divide_by_Zero__int_zero_divide_83_goodB2G::~CWE369_Divide_by_Zero__int_zero_divide_83_goodB2G()
{
    /* FIX: test for a zero denominator */
    if( data != 0 )
    {
        printIntLine(100 / data);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}
}
