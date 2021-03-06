/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_class_16.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 16 Control flow: while(1)
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_class_16
{


void bad()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new TwoIntsClass[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
        break;
    }
}



/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
static void goodB2G()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new TwoIntsClass[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
        break;
    }
    while(1)
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
static void goodG2B()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new TwoIntsClass[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
        break;
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

using namespace CWE415_Double_Free__new_delete_array_class_16; /* so that we can use good and bad easily */

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
