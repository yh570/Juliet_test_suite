/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_62b.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__char_ncat_62
{


void badSource(char * &data)
{
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char * &data)
{
    /* FIX: Properly initialize data */
    data[0] = '\0'; /* null terminate */
}


} /* close namespace */
