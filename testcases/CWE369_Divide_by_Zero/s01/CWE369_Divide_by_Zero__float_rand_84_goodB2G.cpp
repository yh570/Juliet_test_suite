/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_84_goodB2G.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__float_rand_84.h"

namespace CWE369_Divide_by_Zero__float_rand_84
{
CWE369_Divide_by_Zero__float_rand_84_goodB2G::CWE369_Divide_by_Zero__float_rand_84_goodB2G(float dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
}

CWE369_Divide_by_Zero__float_rand_84_goodB2G::~CWE369_Divide_by_Zero__float_rand_84_goodB2G()
{
    /* FIX: Check for value of or near zero before dividing */
    if(fabs(data) > 0.000001)
    {
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}
}
