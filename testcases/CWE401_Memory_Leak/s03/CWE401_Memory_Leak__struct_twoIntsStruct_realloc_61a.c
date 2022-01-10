/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61b_badSource(struct _twoIntsStruct * data);

void CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61_bad()
{
    struct _twoIntsStruct * data;
    data = NULL;
    data = CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61b_badSource(data);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61b_goodG2BSource(struct _twoIntsStruct * data);

static void goodG2B()
{
    struct _twoIntsStruct * data;
    data = NULL;
    data = CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61b_goodG2BSource(data);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
struct _twoIntsStruct * CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61b_goodB2GSource(struct _twoIntsStruct * data);

static void goodB2G()
{
    struct _twoIntsStruct * data;
    data = NULL;
    data = CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61b_goodB2GSource(data);
    /* FIX: Deallocate memory */
    free(data);
}

void CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61_good()
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
    CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE401_Memory_Leak__struct_twoIntsStruct_realloc_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
