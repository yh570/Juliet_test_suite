/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_72b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE675_Duplicate_Operations_on_Resource__fopen_72
{


void badSink(vector<FILE *> dataVector)
{
    /* copy data out of dataVector */
    FILE * data = dataVector[2];
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<FILE *> dataVector)
{
    FILE * data = dataVector[2];
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<FILE *> dataVector)
{
    FILE * data = dataVector[2];
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}


} /* close namespace */
