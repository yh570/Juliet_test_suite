/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_61b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_class_61
{


TwoIntsClass * badSource(TwoIntsClass * data)
{
    data = new TwoIntsClass;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
TwoIntsClass * goodG2BSource(TwoIntsClass * data)
{
    data = new TwoIntsClass;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
TwoIntsClass * goodB2GSource(TwoIntsClass * data)
{
    data = new TwoIntsClass;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    return data;
}


} /* close namespace */
