/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_84_bad.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_wchar_t_84.h"

namespace CWE415_Double_Free__malloc_free_wchar_t_84
{
CWE415_Double_Free__malloc_free_wchar_t_84_bad::CWE415_Double_Free__malloc_free_wchar_t_84_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
}

CWE415_Double_Free__malloc_free_wchar_t_84_bad::~CWE415_Double_Free__malloc_free_wchar_t_84_bad()
{
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}
}
