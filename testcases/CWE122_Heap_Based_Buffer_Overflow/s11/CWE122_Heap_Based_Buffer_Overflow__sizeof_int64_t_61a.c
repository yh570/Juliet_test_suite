/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
int64_t * CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61b_badSource(int64_t * data);

void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61_bad()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61b_badSource(data);
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
int64_t * CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61b_goodG2BSource(int64_t * data);

static void goodG2B()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61b_goodG2BSource(data);
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61_good()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
