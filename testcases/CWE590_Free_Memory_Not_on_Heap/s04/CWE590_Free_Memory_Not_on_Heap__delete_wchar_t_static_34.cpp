/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_static_34.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_static_34
{

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} unionType;


void bad()
{
    wchar_t * data;
    unionType myUnion;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static wchar_t dataBuffer;
        dataBuffer = L'A';
        data = &dataBuffer;
    }
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        printWcharLine(*data);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        delete data;
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    unionType myUnion;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        wchar_t * dataBuffer = new wchar_t;
        *dataBuffer = L'A';
        data = dataBuffer;
    }
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
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

using namespace CWE590_Free_Memory_Not_on_Heap__delete_wchar_t_static_34; /* so that we can use good and bad easily */

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
