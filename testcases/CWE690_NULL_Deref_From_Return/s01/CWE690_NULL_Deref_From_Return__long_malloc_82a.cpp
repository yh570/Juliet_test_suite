/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_malloc_82a.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__long_malloc_82.h"

namespace CWE690_NULL_Deref_From_Return__long_malloc_82
{


void bad()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)malloc(1*sizeof(long));
    CWE690_NULL_Deref_From_Return__long_malloc_82_base* baseObject = new CWE690_NULL_Deref_From_Return__long_malloc_82_bad;
    baseObject->action(data);
    delete baseObject;
}



/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    long * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)malloc(1*sizeof(long));
    CWE690_NULL_Deref_From_Return__long_malloc_82_base* baseObject = new CWE690_NULL_Deref_From_Return__long_malloc_82_goodB2G;
    baseObject->action(data);
    delete baseObject;
}

void good()
{
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE690_NULL_Deref_From_Return__long_malloc_82; /* so that we can use good and bad easily */

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
