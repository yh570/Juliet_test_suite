/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_84_bad.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__freopen_84.h"

namespace CWE675_Duplicate_Operations_on_Resource__freopen_84
{
CWE675_Duplicate_Operations_on_Resource__freopen_84_bad::CWE675_Duplicate_Operations_on_Resource__freopen_84_bad(FILE * dataCopy)
{
    data = dataCopy;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
}

CWE675_Duplicate_Operations_on_Resource__freopen_84_bad::~CWE675_Duplicate_Operations_on_Resource__freopen_84_bad()
{
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}
}
