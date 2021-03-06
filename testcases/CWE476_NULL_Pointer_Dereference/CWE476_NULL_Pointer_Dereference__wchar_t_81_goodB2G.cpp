/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_81_goodB2G.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE476_NULL_Pointer_Dereference__wchar_t_81.h"

namespace CWE476_NULL_Pointer_Dereference__wchar_t_81
{

void CWE476_NULL_Pointer_Dereference__wchar_t_81_goodB2G::action(wchar_t * data) const
{
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        /* printWLine() checks for NULL, so we cannot use it here */
        printWcharLine(data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}

}
