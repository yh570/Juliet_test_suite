/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__long_43.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE457_Use_of_Uninitialized_Variable__long_43
{


static void badSource(long &data)
{
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    long data;
    badSource(data);
    /* POTENTIAL FLAW: Use data without initializing it */
    printLongLine(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSource(long &data)
{
    /* FIX: Initialize data */
    data = 5L;
}

static void goodG2B()
{
    long data;
    goodG2BSource(data);
    /* POTENTIAL FLAW: Use data without initializing it */
    printLongLine(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(long &data)
{
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    long data;
    goodB2GSource(data);
    /* FIX: Ensure data is initialized before use */
    data = 5L;
    printLongLine(data);
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

using namespace CWE457_Use_of_Uninitialized_Variable__long_43; /* so that we can use good and bad easily */

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
