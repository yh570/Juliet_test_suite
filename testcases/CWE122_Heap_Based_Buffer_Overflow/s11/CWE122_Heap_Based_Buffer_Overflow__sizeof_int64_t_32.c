/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_32.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_32_bad()
{
    int64_t * data;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        int64_t * data = *dataPtr1;
        /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
        /* FLAW: Using sizeof the pointer and not the data type in malloc() */
        data = (int64_t *)malloc(sizeof(data));
        if (data == NULL) {exit(-1);}
        *data = 2147483643LL;
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
        printLongLongLine(*data);
        free(data);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t * data;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        int64_t * data = *dataPtr1;
        /* FIX: Using sizeof the data type in malloc() */
        data = (int64_t *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 2147483643LL;
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
        printLongLongLine(*data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_32_good()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
