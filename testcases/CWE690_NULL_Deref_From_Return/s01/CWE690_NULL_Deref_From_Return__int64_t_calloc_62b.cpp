/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_calloc_62b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__int64_t_calloc_62
{


void badSource(int64_t * &data)
{
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)calloc(1, sizeof(int64_t));
}



/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(int64_t * &data)
{
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)calloc(1, sizeof(int64_t));
}


} /* close namespace */
