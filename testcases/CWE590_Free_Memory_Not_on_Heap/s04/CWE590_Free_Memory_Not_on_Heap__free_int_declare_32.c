/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_declare_32.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE590_Free_Memory_Not_on_Heap__free_int_declare_32_bad()
{
    int * data;
    int * *dataPtr1 = &data;
    int * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        int * data = *dataPtr1;
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            int dataBuffer[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5;
                }
            }
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        int * data = *dataPtr2;
        printIntLine(data[0]);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    int * *dataPtr1 = &data;
    int * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        int * data = *dataPtr1;
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int * dataBuffer = (int *)malloc(100*sizeof(int));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5;
                }
            }
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        int * data = *dataPtr2;
        printIntLine(data[0]);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
}

void CWE590_Free_Memory_Not_on_Heap__free_int_declare_32_good()
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
    CWE590_Free_Memory_Not_on_Heap__free_int_declare_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE590_Free_Memory_Not_on_Heap__free_int_declare_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
