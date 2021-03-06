/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_fscanf_sub_74a.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE191_Integer_Underflow__unsigned_int_fscanf_sub_74
{


/* bad function declaration */
void badSink(map<int, unsigned int> dataMap);

void bad()
{
    unsigned int data;
    map<int, unsigned int> dataMap;
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    badSink(dataMap);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, unsigned int> dataMap);

static void goodG2B()
{
    unsigned int data;
    map<int, unsigned int> dataMap;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    goodG2BSink(dataMap);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, unsigned int> dataMap);

static void goodB2G()
{
    unsigned int data;
    map<int, unsigned int> dataMap;
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    goodB2GSink(dataMap);
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

using namespace CWE191_Integer_Underflow__unsigned_int_fscanf_sub_74; /* so that we can use good and bad easily */

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
