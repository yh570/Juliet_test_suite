/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_struct_33.cpp
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE563_Unused_Variable__unused_init_variable_struct_33
{


void bad()
{
    twoIntsStruct data;
    twoIntsStruct &dataRef = data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
    {
        twoIntsStruct data = dataRef;
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct data;
    twoIntsStruct &dataRef = data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
    {
        twoIntsStruct data = dataRef;
        /* FIX: Use data */
        printStructLine(&data);
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

using namespace CWE563_Unused_Variable__unused_init_variable_struct_33; /* so that we can use good and bad easily */

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
