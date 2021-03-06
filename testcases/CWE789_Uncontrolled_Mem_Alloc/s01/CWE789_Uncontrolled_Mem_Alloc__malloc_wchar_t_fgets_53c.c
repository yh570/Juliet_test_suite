/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53c.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#define HELLO_STRING L"hello"


/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53d_badSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53c_badSink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53d_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53d_goodG2BSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53c_goodG2BSink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53d_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53d_goodB2GSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53c_goodB2GSink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_53d_goodB2GSink(data);
}

