/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_43.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE563_Unused_Variable__unused_value_struct_43
{


static void badSource(twoIntsStruct &data)
{
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
}

void bad()
{
    twoIntsStruct data;
    badSource(data);
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.intOne = 1;
    data.intTwo = 1;
    printStructLine(&data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSource(twoIntsStruct &data)
{
    /* FIX: Initialize and use data before it is overwritten */
    data.intOne = 0;
    data.intTwo = 0;
    printStructLine(&data);
}

static void goodG2B()
{
    twoIntsStruct data;
    goodG2BSource(data);
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data.intOne = 1;
    data.intTwo = 1;
    printStructLine(&data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(twoIntsStruct &data)
{
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
}

static void goodB2G()
{
    twoIntsStruct data;
    goodB2GSource(data);
    /* FIX: Use data without over-writing its value */
    printStructLine(&data);
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

using namespace CWE563_Unused_Variable__unused_value_struct_43; /* so that we can use good and bad easily */

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
