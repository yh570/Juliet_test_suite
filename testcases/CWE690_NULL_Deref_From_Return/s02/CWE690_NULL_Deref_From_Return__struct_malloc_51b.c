/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_malloc_51b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-51b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE690_NULL_Deref_From_Return__struct_malloc_51b_badSink(twoIntsStruct * data)
{
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0].intOne = 1;
    data[0].intTwo = 1;
    printStructLine(&data[0]);
    free(data);
}



void CWE690_NULL_Deref_From_Return__struct_malloc_51b_goodB2GSink(twoIntsStruct * data)
{
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0].intOne = 1;
        data[0].intTwo = 1;
        printStructLine(&data[0]);
        free(data);
    }
}

