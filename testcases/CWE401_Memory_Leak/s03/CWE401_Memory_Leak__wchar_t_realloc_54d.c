/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_realloc_54d.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-54d.tmpl.c
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
void CWE401_Memory_Leak__wchar_t_realloc_54e_badSink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_realloc_54d_badSink(wchar_t * data)
{
    CWE401_Memory_Leak__wchar_t_realloc_54e_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE401_Memory_Leak__wchar_t_realloc_54e_goodG2BSink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_realloc_54d_goodG2BSink(wchar_t * data)
{
    CWE401_Memory_Leak__wchar_t_realloc_54e_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE401_Memory_Leak__wchar_t_realloc_54e_goodB2GSink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_realloc_54d_goodB2GSink(wchar_t * data)
{
    CWE401_Memory_Leak__wchar_t_realloc_54e_goodB2GSink(data);
}

