/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_51b.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-51b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE401_Memory_Leak__strdup_wchar_t_51b_badSink(wchar_t * data)
{
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__strdup_wchar_t_51b_goodG2BSink(wchar_t * data)
{
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__strdup_wchar_t_51b_goodB2GSink(wchar_t * data)
{
    /* FIX: Deallocate memory initialized in the source */
    free(data);
}

