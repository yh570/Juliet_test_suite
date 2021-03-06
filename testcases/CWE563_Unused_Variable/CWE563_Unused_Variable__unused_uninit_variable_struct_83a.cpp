/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_struct_83a.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_uninit_variable_struct_83.h"

namespace CWE563_Unused_Variable__unused_uninit_variable_struct_83
{


void bad()
{
    twoIntsStruct data;
    CWE563_Unused_Variable__unused_uninit_variable_struct_83_bad badObject(data);
}



/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct data;
    CWE563_Unused_Variable__unused_uninit_variable_struct_83_goodB2G goodB2GObject(data);
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

using namespace CWE563_Unused_Variable__unused_uninit_variable_struct_83; /* so that we can use good and bad easily */

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
