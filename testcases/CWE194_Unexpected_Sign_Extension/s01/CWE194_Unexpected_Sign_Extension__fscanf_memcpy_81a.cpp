/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81a.cpp
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81.h"

namespace CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81
{


void bad()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%hd", &data);
    const CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81_base& baseObject = CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81_bad();
    baseObject.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    const CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81_base& baseObject = CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81_goodG2B();
    baseObject.action(data);
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE194_Unexpected_Sign_Extension__fscanf_memcpy_81; /* so that we can use good and bad easily */

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
