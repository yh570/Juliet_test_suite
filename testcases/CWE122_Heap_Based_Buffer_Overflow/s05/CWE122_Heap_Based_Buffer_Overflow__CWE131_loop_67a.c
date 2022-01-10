/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-67a.tmpl.c
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


/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_bad()
{
    int * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int) */
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct);

static void goodG2B()
{
    int * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_structType myStruct;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int) */
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67b_goodG2BSink(myStruct);
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
