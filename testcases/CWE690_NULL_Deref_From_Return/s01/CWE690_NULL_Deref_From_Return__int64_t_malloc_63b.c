/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_malloc_63b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE690_NULL_Deref_From_Return__int64_t_malloc_63b_badSink(int64_t * * dataPtr)
{
    int64_t * data = *dataPtr;
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5LL;
    printLongLongLine(data[0]);
    free(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__int64_t_malloc_63b_goodB2GSink(int64_t * * dataPtr)
{
    int64_t * data = *dataPtr;
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5LL;
        printLongLongLine(data[0]);
        free(data);
    }
}

