/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_wchar_t_68b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_wchar_t_68
{

extern wchar_t * badData;
extern wchar_t * goodG2BData;
extern wchar_t * goodB2GData;


void badSink()
{
    wchar_t * data = badData;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink()
{
    wchar_t * data = goodG2BData;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink()
{
    wchar_t * data = goodB2GData;
    /* FIX: Deallocate memory */
    delete[] data;
}


} /* close namespace */
