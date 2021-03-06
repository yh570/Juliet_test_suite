/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_63b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE476_NULL_Pointer_Dereference__char_63b_badSink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printHexCharLine(data[0]);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__char_63b_goodG2BSink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printHexCharLine(data[0]);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE476_NULL_Pointer_Dereference__char_63b_goodB2GSink(char * * dataPtr)
{
    char * data = *dataPtr;
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

