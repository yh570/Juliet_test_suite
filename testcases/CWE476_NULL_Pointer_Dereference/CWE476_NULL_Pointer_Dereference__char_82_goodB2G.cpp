/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_82_goodB2G.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE476_NULL_Pointer_Dereference__char_82.h"

namespace CWE476_NULL_Pointer_Dereference__char_82
{

void CWE476_NULL_Pointer_Dereference__char_82_goodB2G::action(char * data)
{
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        /* printLine() checks for NULL, so we cannot use it here */
        printHexCharLine(data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}

}
