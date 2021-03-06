/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__char_malloc_62b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__char_malloc_62
{


void badSource(char * &data)
{
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (char *)malloc(20*sizeof(char));
}



/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(char * &data)
{
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (char *)malloc(20*sizeof(char));
}


} /* close namespace */
