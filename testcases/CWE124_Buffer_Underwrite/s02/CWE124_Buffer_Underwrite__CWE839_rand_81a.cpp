/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_rand_81a.cpp
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE124_Buffer_Underwrite__CWE839_rand_81.h"

namespace CWE124_Buffer_Underwrite__CWE839_rand_81
{


void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    const CWE124_Buffer_Underwrite__CWE839_rand_81_base& baseObject = CWE124_Buffer_Underwrite__CWE839_rand_81_bad();
    baseObject.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
    * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    const CWE124_Buffer_Underwrite__CWE839_rand_81_base& baseObject = CWE124_Buffer_Underwrite__CWE839_rand_81_goodG2B();
    baseObject.action(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    const CWE124_Buffer_Underwrite__CWE839_rand_81_base& baseObject = CWE124_Buffer_Underwrite__CWE839_rand_81_goodB2G();
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

using namespace CWE124_Buffer_Underwrite__CWE839_rand_81; /* so that we can use good and bad easily */

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
