/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_10.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-10.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_TwoIntsClass_10
{


void bad()
{
    TwoIntsClass * data;
    data = NULL;
    if(globalTrue)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new TwoIntsClass;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
    if(globalTrue)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second globalTrue to globalFalse */
static void goodB2G1()
{
    TwoIntsClass * data;
    data = NULL;
    if(globalTrue)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new TwoIntsClass;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    TwoIntsClass * data;
    data = NULL;
    if(globalTrue)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new TwoIntsClass;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
    if(globalTrue)
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first globalTrue to globalFalse */
static void goodG2B1()
{
    TwoIntsClass * data;
    data = NULL;
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        TwoIntsClass dataGoodBuffer;
        data = &dataGoodBuffer;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
    if(globalTrue)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    TwoIntsClass * data;
    data = NULL;
    if(globalTrue)
    {
        /* FIX: Use memory allocated on the stack */
        TwoIntsClass dataGoodBuffer;
        data = &dataGoodBuffer;
        /* Initialize and make use of data */
        data->intOne = 0;
        data->intTwo = 0;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
    if(globalTrue)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_TwoIntsClass_10; /* so that we can use good and bad easily */

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
