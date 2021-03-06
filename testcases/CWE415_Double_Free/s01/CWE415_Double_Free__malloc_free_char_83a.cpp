/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_83a.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_char_83.h"

namespace CWE415_Double_Free__malloc_free_char_83
{


void bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    CWE415_Double_Free__malloc_free_char_83_bad badObject(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    /* Initialize data */
    data = NULL;
    CWE415_Double_Free__malloc_free_char_83_goodG2B goodG2BObject(data);
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    /* Initialize data */
    data = NULL;
    CWE415_Double_Free__malloc_free_char_83_goodB2G goodB2GObject(data);
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

using namespace CWE415_Double_Free__malloc_free_char_83; /* so that we can use good and bad easily */

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
