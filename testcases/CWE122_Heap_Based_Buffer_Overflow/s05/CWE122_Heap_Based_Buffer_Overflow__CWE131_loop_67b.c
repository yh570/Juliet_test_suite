/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType
{
    int * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType;


void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct)
{
    int * data = myStruct.structFirst;
    {
        int source[10] = {0};
        size_t i;
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct)
{
    int * data = myStruct.structFirst;
    {
        int source[10] = {0};
        size_t i;
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}

