/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_73b.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__malloc_free_int64_t_73
{


void badSink(list<int64_t *> dataList)
{
    /* copy data out of dataList */
    int64_t * data = dataList.back();
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<int64_t *> dataList)
{
    int64_t * data = dataList.back();
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<int64_t *> dataList)
{
    int64_t * data = dataList.back();
    /* do nothing */
    /* FIX: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
