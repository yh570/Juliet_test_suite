/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_long_42.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-42.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_long_42
{


static long * badSource(long * data)
{
    data = new long;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    return data;
}

void bad()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = badSource(data);
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}



/* goodG2B() uses the GoodSource with the BadSink */
static long * goodG2BSource(long * data)
{
    data = new long;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    return data;
}

static void goodG2B()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = goodG2BSource(data);
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

/* goodB2G() uses the BadSource with the GoodSink */
static long * goodB2GSource(long * data)
{
    data = new long;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    return data;
}

static void goodB2G()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = goodB2GSource(data);
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
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

using namespace CWE415_Double_Free__new_delete_long_42; /* so that we can use good and bad easily */

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
