/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_sub_84a.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__int64_t_fscanf_sub_84.h"

namespace CWE191_Integer_Underflow__int64_t_fscanf_sub_84
{


void bad()
{
    int64_t data;
    data = 0LL;
    CWE191_Integer_Underflow__int64_t_fscanf_sub_84_bad * badObject = new CWE191_Integer_Underflow__int64_t_fscanf_sub_84_bad(data);
    delete badObject;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    CWE191_Integer_Underflow__int64_t_fscanf_sub_84_goodG2B * goodG2BObject = new CWE191_Integer_Underflow__int64_t_fscanf_sub_84_goodG2B(data);
    delete goodG2BObject;
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    CWE191_Integer_Underflow__int64_t_fscanf_sub_84_goodB2G * goodB2GObject = new CWE191_Integer_Underflow__int64_t_fscanf_sub_84_goodB2G(data);
    delete goodB2GObject;
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

using namespace CWE191_Integer_Underflow__int64_t_fscanf_sub_84; /* so that we can use good and bad easily */

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
