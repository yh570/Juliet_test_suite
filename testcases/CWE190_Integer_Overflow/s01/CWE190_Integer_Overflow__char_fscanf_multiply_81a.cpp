/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_multiply_81a.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__char_fscanf_multiply_81.h"

namespace CWE190_Integer_Overflow__char_fscanf_multiply_81
{


void bad()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    const CWE190_Integer_Overflow__char_fscanf_multiply_81_base& baseObject = CWE190_Integer_Overflow__char_fscanf_multiply_81_bad();
    baseObject.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    const CWE190_Integer_Overflow__char_fscanf_multiply_81_base& baseObject = CWE190_Integer_Overflow__char_fscanf_multiply_81_goodG2B();
    baseObject.action(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    const CWE190_Integer_Overflow__char_fscanf_multiply_81_base& baseObject = CWE190_Integer_Overflow__char_fscanf_multiply_81_goodB2G();
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

using namespace CWE190_Integer_Overflow__char_fscanf_multiply_81; /* so that we can use good and bad easily */

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
