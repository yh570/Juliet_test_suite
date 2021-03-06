/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int64_t_74b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__new_delete_int64_t_74
{


void badSink(map<int, int64_t *> dataMap)
{
    /* copy data out of dataMap */
    int64_t * data = dataMap[2];
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, int64_t *> dataMap)
{
    int64_t * data = dataMap[2];
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, int64_t *> dataMap)
{
    int64_t * data = dataMap[2];
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
