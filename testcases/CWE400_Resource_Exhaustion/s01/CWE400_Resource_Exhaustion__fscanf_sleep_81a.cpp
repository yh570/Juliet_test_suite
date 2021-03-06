/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_sleep_81a.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__fscanf_sleep_81.h"

namespace CWE400_Resource_Exhaustion__fscanf_sleep_81
{


void bad()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    const CWE400_Resource_Exhaustion__fscanf_sleep_81_base& baseObject = CWE400_Resource_Exhaustion__fscanf_sleep_81_bad();
    baseObject.action(count);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    const CWE400_Resource_Exhaustion__fscanf_sleep_81_base& baseObject = CWE400_Resource_Exhaustion__fscanf_sleep_81_goodG2B();
    baseObject.action(count);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    const CWE400_Resource_Exhaustion__fscanf_sleep_81_base& baseObject = CWE400_Resource_Exhaustion__fscanf_sleep_81_goodB2G();
    baseObject.action(count);
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

using namespace CWE400_Resource_Exhaustion__fscanf_sleep_81; /* so that we can use good and bad easily */

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
