/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_calloc_22b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* The global variable below is used to drive control flow in the sink function */
extern int CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_badGlobal;

void CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_badSink(wchar_t * data)
{
    if(CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_badGlobal)
    {
        /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        wcscpy(data, L"Initialize");
        printWLine(data);
        free(data);
    }
}



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_goodB2G1Global;
extern int CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_goodB2G2Global;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_goodB2G1Sink(wchar_t * data)
{
    if(CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            wcscpy(data, L"Initialize");
            printWLine(data);
            free(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_goodB2G2Sink(wchar_t * data)
{
    if(CWE690_NULL_Deref_From_Return__wchar_t_calloc_22_goodB2G2Global)
    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            wcscpy(data, L"Initialize");
            printWLine(data);
            free(data);
        }
    }
}

