/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_int_84a.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_uninit_variable_int_84.h"

namespace CWE563_Unused_Variable__unused_uninit_variable_int_84
{


void bad()
{
    int data;
    CWE563_Unused_Variable__unused_uninit_variable_int_84_bad * badObject = new CWE563_Unused_Variable__unused_uninit_variable_int_84_bad(data);
    delete badObject;
}



/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    CWE563_Unused_Variable__unused_uninit_variable_int_84_goodB2G * goodB2GObject = new CWE563_Unused_Variable__unused_uninit_variable_int_84_goodB2G(data);
    delete goodB2GObject;
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

using namespace CWE563_Unused_Variable__unused_uninit_variable_int_84; /* so that we can use good and bad easily */

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
