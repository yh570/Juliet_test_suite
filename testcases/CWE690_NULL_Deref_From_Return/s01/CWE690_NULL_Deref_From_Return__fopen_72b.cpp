/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_72b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE690_NULL_Deref_From_Return__fopen_72
{


void badSink(vector<FILE *> dataVector)
{
    /* copy data out of dataVector */
    FILE * data = dataVector[2];
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<FILE *> dataVector)
{
    FILE * data = dataVector[2];
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}


} /* close namespace */
