/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66b_badSink(int * dataArray[]);

void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66_bad()
{
    int * data;
    int * dataArray[5];
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        int * dataBuffer = (int *)ALLOCA(100*sizeof(int));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5;
            }
        }
        data = dataBuffer;
    }
    /* put data in array */
    dataArray[2] = data;
    CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66b_goodG2BSink(int * dataArray[]);

static void goodG2B()
{
    int * data;
    int * dataArray[5];
    data = NULL; /* Initialize data */
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
    dataArray[2] = data;
    CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66b_goodG2BSink(dataArray);
}

void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66_good()
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
    CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE590_Free_Memory_Not_on_Heap__free_int_alloca_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
