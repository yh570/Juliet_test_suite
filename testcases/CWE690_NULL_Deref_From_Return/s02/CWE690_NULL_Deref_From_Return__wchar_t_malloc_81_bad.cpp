/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_bad.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__wchar_t_malloc_81.h"

namespace CWE690_NULL_Deref_From_Return__wchar_t_malloc_81
{

void CWE690_NULL_Deref_From_Return__wchar_t_malloc_81_bad::action(wchar_t * data) const
{
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    wcscpy(data, L"Initialize");
    printWLine(data);
    free(data);
}

}
