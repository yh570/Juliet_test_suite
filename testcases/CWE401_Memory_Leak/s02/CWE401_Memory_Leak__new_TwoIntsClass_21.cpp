/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_21.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-21.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_TwoIntsClass_21
{


/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(TwoIntsClass * data)
{
    if(badStatic)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void bad()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    badStatic = 1; /* true */
    badSink(data);
}



/* The static variables below are used to drive control flow in the sink functions. */
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2bStatic = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
static void goodB2G1Sink(TwoIntsClass * data)
{
    if(goodB2G1Static)
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

static void goodB2G1()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    goodB2G1Static = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
static void goodB2G2Sink(TwoIntsClass * data)
{
    if(goodB2G2Static)
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

static void goodB2G2()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    goodB2G2Static = 1; /* true */
    goodB2G2Sink(data);
}

/* goodG2B() - use goodsource and badsink */
static void goodG2BSink(TwoIntsClass * data)
{
    if(goodG2bStatic)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

static void goodG2B()
{
    TwoIntsClass * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    TwoIntsClass dataGoodBuffer;
    data = &dataGoodBuffer;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    goodG2bStatic = 1; /* true */
    goodG2BSink(data);
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_TwoIntsClass_21; /* so that we can use good and bad easily */

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
