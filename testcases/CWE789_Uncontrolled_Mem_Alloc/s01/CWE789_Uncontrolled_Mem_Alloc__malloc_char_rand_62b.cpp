/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_62b.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_62
{


void badSource(size_t &data)
{
    /* POTENTIAL FLAW: Set data to a random value */
    data = rand();
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(size_t &data)
{
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(size_t &data)
{
    /* POTENTIAL FLAW: Set data to a random value */
    data = rand();
}


} /* close namespace */
