/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_realloc_68b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern int64_t * CWE690_NULL_Deref_From_Return__int64_t_realloc_68_badDataForBadSink;

extern int64_t * CWE690_NULL_Deref_From_Return__int64_t_realloc_68_badDataForGoodSink;


void CWE690_NULL_Deref_From_Return__int64_t_realloc_68b_badSink()
{
    int64_t * data = CWE690_NULL_Deref_From_Return__int64_t_realloc_68_badDataForBadSink;
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5LL;
    printLongLongLine(data[0]);
    free(data);
}



void CWE690_NULL_Deref_From_Return__int64_t_realloc_68b_goodB2GSink()
{
    int64_t * data = CWE690_NULL_Deref_From_Return__int64_t_realloc_68_badDataForGoodSink;
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5LL;
        printLongLongLine(data[0]);
        free(data);
    }
}

