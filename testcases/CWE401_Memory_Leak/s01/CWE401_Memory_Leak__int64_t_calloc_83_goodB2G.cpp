/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int64_t_calloc_83_goodB2G.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
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
#include "CWE401_Memory_Leak__int64_t_calloc_83.h"

namespace CWE401_Memory_Leak__int64_t_calloc_83
{
CWE401_Memory_Leak__int64_t_calloc_83_goodB2G::CWE401_Memory_Leak__int64_t_calloc_83_goodB2G(int64_t * dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (int64_t *)calloc(100, sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0] = 5LL;
    printLongLongLine(data[0]);
}

CWE401_Memory_Leak__int64_t_calloc_83_goodB2G::~CWE401_Memory_Leak__int64_t_calloc_83_goodB2G()
{
    /* FIX: Deallocate memory */
    free(data);
}
}
