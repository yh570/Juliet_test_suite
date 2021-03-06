/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_62b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE675_Duplicate_Operations_on_Resource__freopen_62
{


void badSource(FILE * &data)
{
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(FILE * &data)
{
    /* FIX: Open, but do not close the file in the source */
    data = fopen("GoodSource_fopen.txt", "w+");
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(FILE * &data)
{
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
}


} /* close namespace */
