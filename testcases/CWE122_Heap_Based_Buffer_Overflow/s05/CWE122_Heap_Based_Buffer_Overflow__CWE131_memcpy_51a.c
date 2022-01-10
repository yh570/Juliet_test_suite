/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memcpy
 *    BadSink : Copy array to data using memcpy()
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51b_badSink(int * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51_bad()
{
    int * data;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int) */
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51b_badSink(data);
}



/* good function declarations */
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51b_goodG2BSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int) */
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51b_goodG2BSink(data);
}

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51_good()
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_51_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
