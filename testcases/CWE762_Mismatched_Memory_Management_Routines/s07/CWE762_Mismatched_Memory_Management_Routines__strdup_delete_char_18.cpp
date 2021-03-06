/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_18.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete.label.xml
Template File: sources-sinks-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 18 Control flow: goto statements
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_18
{


void bad()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
    }
    goto sink;
sink:
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
    }
    goto sink;
sink:
    /* FIX: Deallocate the memory using free() */
    free(data);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    goto source;
source:
    /* FIX: Allocate memory from the heap using new */
    data = new char;
    goto sink;
sink:
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
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

using namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_18; /* so that we can use good and bad easily */

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
