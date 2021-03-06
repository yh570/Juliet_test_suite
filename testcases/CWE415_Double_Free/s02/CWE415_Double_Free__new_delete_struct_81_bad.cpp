/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_struct_81_bad.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_struct_81.h"

namespace CWE415_Double_Free__new_delete_struct_81
{

void CWE415_Double_Free__new_delete_struct_81_bad::action(twoIntsStruct * data) const
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

}
