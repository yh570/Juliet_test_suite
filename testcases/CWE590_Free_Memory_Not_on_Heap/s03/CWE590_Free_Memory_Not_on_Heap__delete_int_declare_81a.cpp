/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81a.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81.h"

namespace CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81
{


void bad()
{
    int * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        int dataBuffer;
        dataBuffer = 5;
        data = &dataBuffer;
    }
    const CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81_base& baseObject = CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81_bad();
    baseObject.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        int * dataBuffer = new int;
        *dataBuffer = 5;
        data = dataBuffer;
    }
    const CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81_base& baseObject = CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81_goodG2B();
    baseObject.action(data);
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

using namespace CWE590_Free_Memory_Not_on_Heap__delete_int_declare_81; /* so that we can use good and bad easily */

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
