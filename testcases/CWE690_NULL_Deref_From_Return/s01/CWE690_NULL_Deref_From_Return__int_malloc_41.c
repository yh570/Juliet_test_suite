/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_malloc_41.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


static void badSink(int * data)
{
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5;
    printIntLine(data[0]);
    free(data);
}

void CWE690_NULL_Deref_From_Return__int_malloc_41_bad()
{
    int * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int *)malloc(1*sizeof(int));
    badSink(data);
}



static void goodB2GSink(int * data)
{
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int *)malloc(1*sizeof(int));
    goodB2GSink(data);
}

void CWE690_NULL_Deref_From_Return__int_malloc_41_good()
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
    CWE690_NULL_Deref_From_Return__int_malloc_41_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__int_malloc_41_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
