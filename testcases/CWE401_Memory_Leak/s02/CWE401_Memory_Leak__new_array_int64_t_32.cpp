/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_int64_t_32.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_int64_t_32
{


void bad()
{
    int64_t * data;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    data = NULL;
    {
        int64_t * data = *dataPtr1;
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new int64_t[100];
        /* Initialize and make use of data */
        data[0] = 5LL;
        printLongLongLine(data[0]);
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t * data;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    data = NULL;
    {
        int64_t * data = *dataPtr1;
        /* FIX: Use memory allocated on the stack */
        int64_t dataGoodBuffer[100];
        data = dataGoodBuffer;
        /* Initialize and make use of data */
        data[0] = 5LL;
        printLongLongLine(data[0]);
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int64_t * data;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    data = NULL;
    {
        int64_t * data = *dataPtr1;
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new int64_t[100];
        /* Initialize and make use of data */
        data[0] = 5LL;
        printLongLongLine(data[0]);
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        /* FIX: Deallocate memory */
        delete[] data;
    }
}

void good()
{
    goodG2B();
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_array_int64_t_32; /* so that we can use good and bad easily */

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
