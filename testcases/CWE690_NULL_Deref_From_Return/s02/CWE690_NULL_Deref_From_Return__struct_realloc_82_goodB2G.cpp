/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_realloc_82_goodB2G.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__struct_realloc_82.h"

namespace CWE690_NULL_Deref_From_Return__struct_realloc_82
{

void CWE690_NULL_Deref_From_Return__struct_realloc_82_goodB2G::action(twoIntsStruct * data)
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

}
