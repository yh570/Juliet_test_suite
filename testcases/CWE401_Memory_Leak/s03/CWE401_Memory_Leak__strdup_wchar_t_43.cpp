/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_43.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE401_Memory_Leak__strdup_wchar_t_43
{


static void badSource(wchar_t * &data)
{
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
}

void bad()
{
    wchar_t * data;
    data = NULL;
    badSource(data);
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSource(wchar_t * &data)
{
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize then use data */
    wcscpy(data, L"a string");
    printWLine(data);
}

static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    goodG2BSource(data);
    /* POTENTIAL FLAW: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(wchar_t * &data)
{
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
}

static void goodB2G()
{
    wchar_t * data;
    data = NULL;
    goodB2GSource(data);
    /* FIX: Deallocate memory initialized in the source */
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

using namespace CWE401_Memory_Leak__strdup_wchar_t_43; /* so that we can use good and bad easily */

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
