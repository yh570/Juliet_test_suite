/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_malloc_17.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE690_NULL_Deref_From_Return__int64_t_malloc_17_bad()
{
    int j;
    int64_t * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)malloc(1*sizeof(int64_t));
    for(j = 0; j < 1; j++)
    {
        /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5LL;
        printLongLongLine(data[0]);
        free(data);
    }
}



/* goodB2G() - use the goodsink in the for statement */
static void goodB2G()
{
    int k;
    int64_t * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)malloc(1*sizeof(int64_t));
    for(k = 0; k < 1; k++)
    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0] = 5LL;
            printLongLongLine(data[0]);
            free(data);
        }
    }
}

void CWE690_NULL_Deref_From_Return__int64_t_malloc_17_good()
{
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
    CWE690_NULL_Deref_From_Return__int64_t_malloc_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__int64_t_malloc_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
