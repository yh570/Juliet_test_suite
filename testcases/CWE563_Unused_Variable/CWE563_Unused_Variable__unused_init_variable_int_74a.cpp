/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int_74a.cpp
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_init_variable_int_74
{


/* bad function declaration */
void badSink(map<int, int> dataMap);

void bad()
{
    int data;
    map<int, int> dataMap;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5;
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    badSink(dataMap);
}



/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, int> dataMap);

static void goodB2G()
{
    int data;
    map<int, int> dataMap;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5;
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    goodB2GSink(dataMap);
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

using namespace CWE563_Unused_Variable__unused_init_variable_int_74; /* so that we can use good and bad easily */

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
