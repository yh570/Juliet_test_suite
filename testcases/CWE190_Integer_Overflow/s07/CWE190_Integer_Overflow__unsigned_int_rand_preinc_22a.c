/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_preinc_22a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the sink function */
int CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_badGlobal = 0;

void CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_badSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_badGlobal = 1; /* true */
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_badSink(data);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G1Global = 0;
int CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G2Global = 0;
int CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodG2BGlobal = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G1Sink(unsigned int data);

static void goodB2G1()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G1Global = 0; /* false */
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G2Sink(unsigned int data);

static void goodB2G2()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G2Global = 1; /* true */
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodB2G2Sink(data);
}

/* goodG2B() - use goodsource and badsink */
void CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodG2BSink(unsigned int data);

static void goodG2B()
{
    unsigned int data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodG2BGlobal = 1; /* true */
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_goodG2BSink(data);
}

void CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_rand_preinc_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
