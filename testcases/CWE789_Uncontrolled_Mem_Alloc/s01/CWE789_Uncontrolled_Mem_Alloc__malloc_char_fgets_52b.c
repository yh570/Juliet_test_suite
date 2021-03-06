/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#define HELLO_STRING "hello"


/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52c_badSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52b_badSink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52c_goodG2BSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52b_goodG2BSink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52c_goodB2GSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52b_goodB2GSink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_52c_goodB2GSink(data);
}

