/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_42.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete.label.xml
Template File: sources-sinks-42.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_42
{


static char * badSource(char * data)
{
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
    }
    return data;
}

void bad()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    data = badSource(data);
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}



/* goodG2B() uses the GoodSource with the BadSink */
static char * goodG2BSource(char * data)
{
    /* FIX: Allocate memory from the heap using new */
    data = new char;
    return data;
}

static void goodG2B()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    data = goodG2BSource(data);
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}

/* goodB2G() uses the BadSource with the GoodSink */
static char * goodB2GSource(char * data)
{
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = strdup(myString);
    }
    return data;
}

static void goodB2G()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    data = goodB2GSource(data);
    /* FIX: Deallocate the memory using free() */
    free(data);
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

using namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_42; /* so that we can use good and bad easily */

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
