/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53c_badSink(int * data);

void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53b_badSink(int * data)
{
    CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53c_badSink(data);
}



/* good function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53c_goodG2BSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53b_goodG2BSink(int * data)
{
    CWE590_Free_Memory_Not_on_Heap__free_int_alloca_53c_goodG2BSink(data);
}

