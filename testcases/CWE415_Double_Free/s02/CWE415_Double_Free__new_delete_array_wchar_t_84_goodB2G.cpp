/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_wchar_t_84_goodB2G.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_array_wchar_t_84.h"

namespace CWE415_Double_Free__new_delete_array_wchar_t_84
{
CWE415_Double_Free__new_delete_array_wchar_t_84_goodB2G::CWE415_Double_Free__new_delete_array_wchar_t_84_goodB2G(wchar_t * dataCopy)
{
    data = dataCopy;
    data = new wchar_t[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
}

CWE415_Double_Free__new_delete_array_wchar_t_84_goodB2G::~CWE415_Double_Free__new_delete_array_wchar_t_84_goodB2G()
{
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}
}
