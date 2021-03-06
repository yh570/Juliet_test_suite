/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_char_declare_72b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_char_declare_72
{


void badSink(vector<char *> dataVector)
{
    /* copy data out of dataVector */
    char * data = dataVector[2];
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<char *> dataVector)
{
    char * data = dataVector[2];
    printLine(data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}


} /* close namespace */
