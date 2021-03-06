/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_malloc_32.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE401_Memory_Leak__twoIntsStruct_malloc_32_bad()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    data = NULL;
    {
        twoIntsStruct * data = *dataPtr1;
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    data = NULL;
    {
        twoIntsStruct * data = *dataPtr1;
        /* FIX: Use memory allocated on the stack with ALLOCA */
        data = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct * data;
    twoIntsStruct * *dataPtr1 = &data;
    twoIntsStruct * *dataPtr2 = &data;
    data = NULL;
    {
        twoIntsStruct * data = *dataPtr1;
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine(&data[0]);
        *dataPtr1 = data;
    }
    {
        twoIntsStruct * data = *dataPtr2;
        /* FIX: Deallocate memory */
        free(data);
    }
}

void CWE401_Memory_Leak__twoIntsStruct_malloc_32_good()
{
    goodG2B();
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE401_Memory_Leak__twoIntsStruct_malloc_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE401_Memory_Leak__twoIntsStruct_malloc_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
