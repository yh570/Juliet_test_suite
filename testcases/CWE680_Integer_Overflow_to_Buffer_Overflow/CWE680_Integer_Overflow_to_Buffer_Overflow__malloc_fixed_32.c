/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_32.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fixed Fixed value that will cause an integer overflow in the sink
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_32_bad()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = -1;
    {
        int data = *dataPtr1;
        /* FLAW: Set data to a value that will cause an integer overflow in the call to malloc() in the sink */
        data = INT_MAX / 2 + 2; /* 1073741825 */
        /* NOTE: This value will cause the sink to only allocate 4 bytes of memory, however
         * the for loop will attempt to access indices 0-1073741824 */
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            size_t i;
            int *intPointer;
            /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             * so that the for loop doing the initialization causes a buffer overflow */
            intPointer = (int*)malloc(data * sizeof(int));
            if (intPointer == NULL) {exit(-1);}
            for (i = 0; i < (size_t)data; i++)
            {
                intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
            }
            printIntLine(intPointer[0]);
            free(intPointer);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = -1;
    {
        int data = *dataPtr1;
        /* FIX: Set data to a relatively small number greater than zero */
        data = 20;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            size_t i;
            int *intPointer;
            /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
             * so that the for loop doing the initialization causes a buffer overflow */
            intPointer = (int*)malloc(data * sizeof(int));
            if (intPointer == NULL) {exit(-1);}
            for (i = 0; i < (size_t)data; i++)
            {
                intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
            }
            printIntLine(intPointer[0]);
            free(intPointer);
        }
    }
}

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_32_good()
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
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
