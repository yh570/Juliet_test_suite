/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_83_goodG2B.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_long_83.h"

namespace CWE415_Double_Free__malloc_free_long_83
{
CWE415_Double_Free__malloc_free_long_83_goodG2B::CWE415_Double_Free__malloc_free_long_83_goodG2B(long * dataCopy)
{
    data = dataCopy;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* FIX: Do NOT free data in the source - the bad sink frees data */
}

CWE415_Double_Free__malloc_free_long_83_goodG2B::~CWE415_Double_Free__malloc_free_long_83_goodG2B()
{
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}
}
