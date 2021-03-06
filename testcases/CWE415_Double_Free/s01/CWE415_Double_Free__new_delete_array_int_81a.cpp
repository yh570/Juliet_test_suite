/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int_81a.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_array_int_81.h"

namespace CWE415_Double_Free__new_delete_array_int_81
{


void bad()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = new int[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    const CWE415_Double_Free__new_delete_array_int_81_base& o = CWE415_Double_Free__new_delete_array_int_81_bad();
    o.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = new int[100];
    /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    const CWE415_Double_Free__new_delete_array_int_81_base& baseObject = CWE415_Double_Free__new_delete_array_int_81_goodG2B();
    baseObject.action(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = new int[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    const CWE415_Double_Free__new_delete_array_int_81_base& baseObject = CWE415_Double_Free__new_delete_array_int_81_goodB2G();
    baseObject.action(data);
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

using namespace CWE415_Double_Free__new_delete_array_int_81; /* so that we can use good and bad easily */

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
