/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_char_41.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-41.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_char_41
{


static void badSink(char * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

void bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = new char[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    badSink(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(char * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

static void goodG2B()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = new char[100];
    /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    goodG2BSink(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink(char * data)
{
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = new char[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    goodB2GSink(data);
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

using namespace CWE415_Double_Free__new_delete_array_char_41; /* so that we can use good and bad easily */

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
