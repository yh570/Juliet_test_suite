/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_18.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 18 Control flow: goto statements
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_18
{


void bad()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new int64_t[100];
    goto sink;
sink:
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new int64_t[100];
    goto sink;
sink:
    /* FIX: Deallocate the memory using delete [] */
    delete [] data;
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* FIX: Allocate memory from the heap using new */
    data = new int64_t;
    goto sink;
sink:
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_18; /* so that we can use good and bad easily */

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
