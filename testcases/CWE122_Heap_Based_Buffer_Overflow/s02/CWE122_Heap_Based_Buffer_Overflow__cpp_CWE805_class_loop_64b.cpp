/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_64b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy TwoIntsClass array to data using a loop
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_64
{


void badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    TwoIntsClass * * dataPtr = (TwoIntsClass * *)dataVoidPtr;
    /* dereference dataPtr into data */
    TwoIntsClass * data = (*dataPtr);
    {
        TwoIntsClass source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0].intOne);
            delete [] data;
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    TwoIntsClass * * dataPtr = (TwoIntsClass * *)dataVoidPtr;
    /* dereference dataPtr into data */
    TwoIntsClass * data = (*dataPtr);
    {
        TwoIntsClass source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0].intOne);
            delete [] data;
        }
    }
}


} /* close namespace */
