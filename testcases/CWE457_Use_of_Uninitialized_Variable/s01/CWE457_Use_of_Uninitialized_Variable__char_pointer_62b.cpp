/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__char_pointer_62b.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE457_Use_of_Uninitialized_Variable__char_pointer_62
{


void badSource(char * &data)
{
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char * &data)
{
    /* FIX: Initialize data */
    data = "string";
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(char * &data)
{
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
