/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int_12.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int_12
{


void bad()
{
    int * data;
    /* Initialize data*/
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new int;
    }
    else
    {
        /* FIX: Allocate memory from the heap using new [] */
        data = new int[100];
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
    else
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
}



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    int * data;
    /* Initialize data*/
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new int;
    }
    else
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new int;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
    else
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    int * data;
    /* Initialize data*/
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Allocate memory from the heap using new [] */
        data = new int[100];
    }
    else
    {
        /* FIX: Allocate memory from the heap using new [] */
        data = new int[100];
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
    else
    {
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int_12; /* so that we can use good and bad easily */

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
