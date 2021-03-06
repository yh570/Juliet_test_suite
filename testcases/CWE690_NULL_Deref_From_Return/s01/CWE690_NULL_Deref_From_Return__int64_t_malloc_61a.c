/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_malloc_61a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
int64_t * CWE690_NULL_Deref_From_Return__int64_t_malloc_61b_badSource(int64_t * data);

void CWE690_NULL_Deref_From_Return__int64_t_malloc_61_bad()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    data = CWE690_NULL_Deref_From_Return__int64_t_malloc_61b_badSource(data);
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5LL;
    printLongLongLine(data[0]);
    free(data);
}



/* goodB2G uses the BadSource with the GoodSink */
int64_t * CWE690_NULL_Deref_From_Return__int64_t_malloc_61b_goodB2GSource(int64_t * data);

static void goodB2G()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    data = CWE690_NULL_Deref_From_Return__int64_t_malloc_61b_goodB2GSource(data);
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5LL;
        printLongLongLine(data[0]);
        free(data);
    }
}

void CWE690_NULL_Deref_From_Return__int64_t_malloc_61_good()
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
    CWE690_NULL_Deref_From_Return__int64_t_malloc_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__int64_t_malloc_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
