/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_74a.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE400_Resource_Exhaustion__fscanf_for_loop_74
{


/* bad function declaration */
void badSink(map<int, int> countMap);

void bad()
{
    int count;
    map<int, int> countMap;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    /* Put count in a map */
    countMap[0] = count;
    countMap[1] = count;
    countMap[2] = count;
    badSink(countMap);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, int> countMap);

static void goodG2B()
{
    int count;
    map<int, int> countMap;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    /* Put count in a map */
    countMap[0] = count;
    countMap[1] = count;
    countMap[2] = count;
    goodG2BSink(countMap);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, int> countMap);

static void goodB2G()
{
    int count;
    map<int, int> countMap;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    countMap[0] = count;
    countMap[1] = count;
    countMap[2] = count;
    goodB2GSink(countMap);
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

using namespace CWE400_Resource_Exhaustion__fscanf_for_loop_74; /* so that we can use good and bad easily */

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
