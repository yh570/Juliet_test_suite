/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twoIntsStruct_12.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_twoIntsStruct_12
{


void bad()
{
    twoIntsStruct * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new twoIntsStruct;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printStructLine(data);
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        twoIntsStruct dataGoodBuffer;
        data = &dataGoodBuffer;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printStructLine(data);
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    twoIntsStruct * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new twoIntsStruct;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printStructLine(data);
    }
    else
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new twoIntsStruct;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printStructLine(data);
    }
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Deallocate memory */
        delete data;
    }
    else
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    twoIntsStruct * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Use memory allocated on the stack */
        twoIntsStruct dataGoodBuffer;
        data = &dataGoodBuffer;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printStructLine(data);
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        twoIntsStruct dataGoodBuffer;
        data = &dataGoodBuffer;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printStructLine(data);
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void good()
{
    goodB2G();
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_twoIntsStruct_12; /* so that we can use good and bad easily */

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
