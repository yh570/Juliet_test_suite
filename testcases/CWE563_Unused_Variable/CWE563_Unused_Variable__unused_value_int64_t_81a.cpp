/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int64_t_81a.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_value_int64_t_81.h"

namespace CWE563_Unused_Variable__unused_value_int64_t_81
{


void bad()
{
    int64_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5LL;
    const CWE563_Unused_Variable__unused_value_int64_t_81_base& baseObject = CWE563_Unused_Variable__unused_value_int64_t_81_bad();
    baseObject.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t data;
    /* FIX: Initialize and use data before it is overwritten */
    data = 5LL;
    printLongLongLine(data);
    const CWE563_Unused_Variable__unused_value_int64_t_81_base& baseObject = CWE563_Unused_Variable__unused_value_int64_t_81_goodG2B();
    baseObject.action(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int64_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5LL;
    const CWE563_Unused_Variable__unused_value_int64_t_81_base& baseObject = CWE563_Unused_Variable__unused_value_int64_t_81_goodB2G();
    baseObject.action(data);
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

using namespace CWE563_Unused_Variable__unused_value_int64_t_81; /* so that we can use good and bad easily */

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
