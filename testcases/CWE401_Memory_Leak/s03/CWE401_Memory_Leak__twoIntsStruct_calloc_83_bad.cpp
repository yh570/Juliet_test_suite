/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_calloc_83_bad.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE401_Memory_Leak__twoIntsStruct_calloc_83.h"

namespace CWE401_Memory_Leak__twoIntsStruct_calloc_83
{
CWE401_Memory_Leak__twoIntsStruct_calloc_83_bad::CWE401_Memory_Leak__twoIntsStruct_calloc_83_bad(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoIntsStruct *)calloc(100, sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
}

CWE401_Memory_Leak__twoIntsStruct_calloc_83_bad::~CWE401_Memory_Leak__twoIntsStruct_calloc_83_bad()
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}
}
