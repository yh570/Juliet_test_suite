/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_67b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_67
{

typedef struct _structType
{
    int * structFirst;
} structType;


void badSink(structType myStruct)
{
    int * data = myStruct.structFirst;
    {
        int source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
        delete [] data;
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct)
{
    int * data = myStruct.structFirst;
    {
        int source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
        delete [] data;
    }
}


} /* close namespace */
