/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int64_t_83_goodG2B.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_int64_t_83.h"

namespace CWE415_Double_Free__new_delete_int64_t_83
{
CWE415_Double_Free__new_delete_int64_t_83_goodG2B::CWE415_Double_Free__new_delete_int64_t_83_goodG2B(int64_t * dataCopy)
{
    data = dataCopy;
    data = new int64_t;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
}

CWE415_Double_Free__new_delete_int64_t_83_goodG2B::~CWE415_Double_Free__new_delete_int64_t_83_goodG2B()
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}
}
