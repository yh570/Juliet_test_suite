/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int64_t_static_31.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-31.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_static_31
{


void bad()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static int64_t dataBuffer;
        dataBuffer = 5LL;
        data = &dataBuffer;
    }
    {
        int64_t * dataCopy = data;
        int64_t * data = dataCopy;
        printLongLongLine(*data);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        delete data;
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        int64_t * dataBuffer = new int64_t;
        *dataBuffer = 5LL;
        data = dataBuffer;
    }
    {
        int64_t * dataCopy = data;
        int64_t * data = dataCopy;
        printLongLongLine(*data);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        delete data;
    }
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_static_31; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
