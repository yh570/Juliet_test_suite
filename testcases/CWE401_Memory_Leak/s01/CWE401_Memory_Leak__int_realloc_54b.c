/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_realloc_54b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE401_Memory_Leak__int_realloc_54c_badSink(int * data);

void CWE401_Memory_Leak__int_realloc_54b_badSink(int * data)
{
    CWE401_Memory_Leak__int_realloc_54c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__int_realloc_54c_goodG2BSink(int * data);

void CWE401_Memory_Leak__int_realloc_54b_goodG2BSink(int * data)
{
    CWE401_Memory_Leak__int_realloc_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__int_realloc_54c_goodB2GSink(int * data);

void CWE401_Memory_Leak__int_realloc_54b_goodB2GSink(int * data)
{
    CWE401_Memory_Leak__int_realloc_54c_goodB2GSink(data);
}

