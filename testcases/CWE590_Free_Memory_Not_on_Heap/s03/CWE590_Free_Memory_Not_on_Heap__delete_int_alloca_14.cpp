/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int_alloca_14.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-14.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_int_alloca_14
{


void bad()
{
    int * data;
    data = NULL; /* Initialize data */
    if(globalFive==5)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            int * dataBuffer = (int *)ALLOCA(sizeof(int));
            *dataBuffer = 5;
            data = dataBuffer;
        }
    }
    printIntLine(*data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}



/* goodG2B1() - use goodsource and badsink by changing the globalFive==5 to globalFive!=5 */
static void goodG2B1()
{
    int * data;
    data = NULL; /* Initialize data */
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int * dataBuffer = new int;
            *dataBuffer = 5;
            data = dataBuffer;
        }
    }
    printIntLine(*data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int * data;
    data = NULL; /* Initialize data */
    if(globalFive==5)
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int * dataBuffer = new int;
            *dataBuffer = 5;
            data = dataBuffer;
        }
    }
    printIntLine(*data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}

void good()
{
    goodG2B1();
    goodG2B2();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Memory_Not_on_Heap__delete_int_alloca_14; /* so that we can use good and bad easily */

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
