/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_static_68b.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern int * CWE590_Free_Memory_Not_on_Heap__free_int_static_68_badData;
extern int * CWE590_Free_Memory_Not_on_Heap__free_int_static_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE590_Free_Memory_Not_on_Heap__free_int_static_68b_badSink()
{
    int * data = CWE590_Free_Memory_Not_on_Heap__free_int_static_68_badData;
    printIntLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE590_Free_Memory_Not_on_Heap__free_int_static_68b_goodG2BSink()
{
    int * data = CWE590_Free_Memory_Not_on_Heap__free_int_static_68_goodG2BData;
    printIntLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

