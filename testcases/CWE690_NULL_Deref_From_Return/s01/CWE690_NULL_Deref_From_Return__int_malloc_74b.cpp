/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_malloc_74b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE690_NULL_Deref_From_Return__int_malloc_74
{


void badSink(map<int, int *> dataMap)
{
    /* copy data out of dataMap */
    int * data = dataMap[2];
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5;
    printIntLine(data[0]);
    free(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, int *> dataMap)
{
    int * data = dataMap[2];
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}


} /* close namespace */
