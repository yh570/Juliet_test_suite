/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int_45.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-45.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_int_45
{

static int * badData;
static int * goodG2BData;
static int * goodB2GData;


static void badSink()
{
    int * data = badData;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    int * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int * data = goodG2BData;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

static void goodG2B()
{
    int * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    int dataGoodBuffer;
    data = &dataGoodBuffer;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    int * data = goodB2GData;
    /* FIX: Deallocate memory */
    delete data;
}

static void goodB2G()
{
    int * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int;
    /* Initialize and make use of data */
    *data = 5;
    printIntLine(*data);
    goodB2GData = data;
    goodB2GSink();
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

using namespace CWE401_Memory_Leak__new_int_45; /* so that we can use good and bad easily */

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
