/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67_structType
{
    twoIntsStruct * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67_structType;


void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

