/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_large_22a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-22a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_large_22
{


/* The global variable below is used to drive control flow in the sink function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
int badGlobal = 0;

void badSink(int data);

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
    badGlobal = 1; /* true */
    badSink(data);
}



/* The global variables below are used to drive control flow in the sink functions. Since they are in
a C++ namespace, they don't need globally unique names. */
int goodB2G1Global = 0;
int goodB2G2Global = 0;
int goodG2B1Global = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void goodB2G1Sink(int data);

static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
    goodB2G1Global = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void goodB2G2Sink(int data);

static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
    goodB2G2Global = 1; /* true */
    goodB2G2Sink(data);
}

/* goodG2B1() - use goodsource and badsink */
void goodG2B1Sink(int data);

static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    goodG2B1Global = 1; /* true */
    goodG2B1Sink(data);
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_large_22; /* so that we can use good and bad easily */

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
