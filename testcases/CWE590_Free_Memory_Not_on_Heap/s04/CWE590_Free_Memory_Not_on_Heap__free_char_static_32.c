/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_char_static_32.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE590_Free_Memory_Not_on_Heap__free_char_static_32_bad()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        char * data = *dataPtr1;
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            static char dataBuffer[100];
            memset(dataBuffer, 'A', 100-1); /* fill with 'A's */
            dataBuffer[100-1] = '\0'; /* null terminate */
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        printLine(data);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        char * data = *dataPtr1;
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            memset(dataBuffer, 'A', 100-1); /* fill with 'A's */
            dataBuffer[100-1] = '\0'; /* null terminate */
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        printLine(data);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
}

void CWE590_Free_Memory_Not_on_Heap__free_char_static_32_good()
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
    CWE590_Free_Memory_Not_on_Heap__free_char_static_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE590_Free_Memory_Not_on_Heap__free_char_static_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
