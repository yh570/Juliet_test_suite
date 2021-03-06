/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_malloc_63a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-63a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__int_malloc_63b_badSink(int * * dataPtr);

void CWE690_NULL_Deref_From_Return__int_malloc_63_bad()
{
    int * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int *)malloc(1*sizeof(int));
    CWE690_NULL_Deref_From_Return__int_malloc_63b_badSink(&data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__int_malloc_63b_goodB2GSink(int * * data);

static void goodB2G()
{
    int * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int *)malloc(1*sizeof(int));
    CWE690_NULL_Deref_From_Return__int_malloc_63b_goodB2GSink(&data);
}

void CWE690_NULL_Deref_From_Return__int_malloc_63_good()
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
    CWE690_NULL_Deref_From_Return__int_malloc_63_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__int_malloc_63_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
