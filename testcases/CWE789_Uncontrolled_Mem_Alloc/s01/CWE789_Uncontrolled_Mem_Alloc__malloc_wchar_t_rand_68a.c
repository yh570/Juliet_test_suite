/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_badData;
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_goodG2BData;
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_goodB2GData;


/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_badSink();

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_bad()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = rand();
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_badData = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_badSink();
}



/* good function declarations */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_goodG2BSink();
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_goodG2BData = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = rand();
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_goodB2GData = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_goodB2GSink();
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
