/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_struct_static_67b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE590_Free_Memory_Not_on_Heap__free_struct_static_67_structType
{
    twoIntsStruct * structFirst;
} CWE590_Free_Memory_Not_on_Heap__free_struct_static_67_structType;


void CWE590_Free_Memory_Not_on_Heap__free_struct_static_67b_badSink(CWE590_Free_Memory_Not_on_Heap__free_struct_static_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Memory_Not_on_Heap__free_struct_static_67b_goodG2BSink(CWE590_Free_Memory_Not_on_Heap__free_struct_static_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    printStructLine(&data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

