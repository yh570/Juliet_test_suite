/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_realloc_62b.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE401_Memory_Leak__twoIntsStruct_realloc_62
{


void badSource(twoIntsStruct * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoIntsStruct *)realloc(data, 100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
}



/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(twoIntsStruct * &data)
{
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(twoIntsStruct * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (twoIntsStruct *)realloc(data, 100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
}


} /* close namespace */
