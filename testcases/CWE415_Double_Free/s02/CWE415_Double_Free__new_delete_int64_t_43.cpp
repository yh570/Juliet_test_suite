/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int64_t_43.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_int64_t_43
{


void badSource(int64_t * &data)
{
    data = new int64_t;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
}

void bad()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    badSource(data);
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSource(int64_t * &data)
{
    data = new int64_t;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
}

static void goodG2B()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    goodG2BSource(data);
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(int64_t * &data)
{
    data = new int64_t;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
}

static void goodB2G()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    goodB2GSource(data);
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

using namespace CWE415_Double_Free__new_delete_int64_t_43; /* so that we can use good and bad easily */

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
