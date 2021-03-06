/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING "hello"


/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65b_badSink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65_bad()
{
    size_t data;
    /* define a function pointer */
    void (*funcPtr) (size_t) = CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65b_badSink;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65b_goodG2BSink(size_t data);

static void goodG2B()
{
    size_t data;
    void (*funcPtr) (size_t) = CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65b_goodG2BSink;
    /* Initialize data */
    data = 0;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65b_goodB2GSink(size_t data);

static void goodB2G()
{
    size_t data;
    void (*funcPtr) (size_t) = CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65b_goodB2GSink;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    funcPtr(data);
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_fscanf_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
