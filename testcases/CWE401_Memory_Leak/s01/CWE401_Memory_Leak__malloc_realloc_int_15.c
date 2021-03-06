/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_int_15.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE401_Memory_Leak__malloc_realloc_int_15_bad()
{
    switch(6)
    {
    case 6:
    {
        int * data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        /* FLAW: If realloc() fails, the initial memory block will not be freed() */
        data = (int *)realloc(data, (130000)*sizeof(int));
        if (data != NULL)
        {
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
            free(data);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}



/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        int * data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        int * tmpData;
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        tmpData = (int *)realloc(data, (130000)*sizeof(int));
        /* FIX: Ensure realloc() was successful before assigning data to the memory block
        * allocated with realloc() */
        if (tmpData != NULL)
        {
            data = tmpData;
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
        }
        free(data);
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        int * data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        int * tmpData;
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        tmpData = (int *)realloc(data, (130000)*sizeof(int));
        /* FIX: Ensure realloc() was successful before assigning data to the memory block
        * allocated with realloc() */
        if (tmpData != NULL)
        {
            data = tmpData;
            /* Reinitialize and make use of data */
            data[0] = 10;
            printIntLine(data[0]);
        }
        free(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE401_Memory_Leak__malloc_realloc_int_15_good()
{
    good1();
    good2();
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
    CWE401_Memory_Leak__malloc_realloc_int_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_int_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
