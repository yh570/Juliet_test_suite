/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_placement_new_32.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: placement_new Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_placement_new_32
{


void bad()
{
    wchar_t * data;
    wchar_t * *dataPtr1 = &data;
    wchar_t * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        wchar_t * data = *dataPtr1;
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            char buffer[sizeof(wchar_t)];
            wchar_t * dataBuffer = new(buffer) wchar_t;
            *dataBuffer = L'A';
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        wchar_t * data = *dataPtr2;
        printWcharLine(*data);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        delete data;
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *dataPtr1 = &data;
    wchar_t * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        wchar_t * data = *dataPtr1;
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            wchar_t * dataBuffer = new wchar_t;
            *dataBuffer = L'A';
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        wchar_t * data = *dataPtr2;
        printWcharLine(*data);
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

using namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_placement_new_32; /* so that we can use good and bad easily */

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
