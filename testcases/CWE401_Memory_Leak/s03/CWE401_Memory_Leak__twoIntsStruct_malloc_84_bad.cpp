/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_malloc_84_bad.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE401_Memory_Leak__twoIntsStruct_malloc_84.h"

namespace CWE401_Memory_Leak__twoIntsStruct_malloc_84
{
CWE401_Memory_Leak__twoIntsStruct_malloc_84_bad::CWE401_Memory_Leak__twoIntsStruct_malloc_84_bad(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
}

CWE401_Memory_Leak__twoIntsStruct_malloc_84_bad::~CWE401_Memory_Leak__twoIntsStruct_malloc_84_bad()
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}
}
