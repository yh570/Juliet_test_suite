/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_83_goodB2G.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE401_Memory_Leak__strdup_wchar_t_83.h"

namespace CWE401_Memory_Leak__strdup_wchar_t_83
{
CWE401_Memory_Leak__strdup_wchar_t_83_goodB2G::CWE401_Memory_Leak__strdup_wchar_t_83_goodB2G(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
}

CWE401_Memory_Leak__strdup_wchar_t_83_goodB2G::~CWE401_Memory_Leak__strdup_wchar_t_83_goodB2G()
{
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}
}
