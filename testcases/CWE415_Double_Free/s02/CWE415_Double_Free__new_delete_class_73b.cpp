/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_73b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__new_delete_class_73
{


void badSink(list<TwoIntsClass *> dataList)
{
    /* copy data out of dataList */
    TwoIntsClass * data = dataList.back();
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<TwoIntsClass *> dataList)
{
    TwoIntsClass * data = dataList.back();
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<TwoIntsClass *> dataList)
{
    TwoIntsClass * data = dataList.back();
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
