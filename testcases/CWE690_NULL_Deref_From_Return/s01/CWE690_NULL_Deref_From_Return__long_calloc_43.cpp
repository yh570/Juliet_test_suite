/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_calloc_43.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__long_calloc_43
{


static void badSource(long * &data)
{
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
}

void bad()
{
    long * data;
    data = NULL; /* Initialize data */
    badSource(data);
    /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5L;
    printLongLine(data[0]);
    free(data);
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(long * &data)
{
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
}

static void goodB2G()
{
    long * data;
    data = NULL; /* Initialize data */
    goodB2GSource(data);
    /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5L;
        printLongLine(data[0]);
        free(data);
    }
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

using namespace CWE690_NULL_Deref_From_Return__long_calloc_43; /* so that we can use good and bad easily */

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
