/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_82_bad.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_82.h"

#define HELLO_STRING "hello"

namespace CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_82
{

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_82_bad::action(size_t data)
{
    {
        char * myString;
        /* POTENTIAL FLAW: No MAXIMUM limitation for memory allocation, but ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING))
        {
            myString = (char *)malloc(data*sizeof(char));
            if (myString == NULL) {exit(-1);}
            /* Copy a small string into myString */
            strcpy(myString, HELLO_STRING);
            printLine(myString);
            free(myString);
        }
        else
        {
            printLine("Input is less than the length of the source string");
        }
    }
}

}
