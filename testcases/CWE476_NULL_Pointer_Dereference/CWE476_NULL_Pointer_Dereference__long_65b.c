/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_65b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE476_NULL_Pointer_Dereference__long_65b_badSink(long * data)
{
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLine(*data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__long_65b_goodG2BSink(long * data)
{
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLine(*data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE476_NULL_Pointer_Dereference__long_65b_goodB2GSink(long * data)
{
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        printLongLine(*data);
    }
    else
    {
        printLine("data is NULL");
    }
}

