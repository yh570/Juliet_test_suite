/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_72b.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE401_Memory_Leak__strdup_char_72
{


void badSink(vector<char *> dataVector)
{
    /* copy data out of dataVector */
    char * data = dataVector[2];
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}


} /* close namespace */
