/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_21.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"


/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(unsigned int data)
{
    if(badStatic)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_21_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    badStatic = 1; /* true */
    badSink(data);
}



/* The static variables below are used to drive control flow in the sink functions. */
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
static void goodB2G1Sink(unsigned int data)
{
    if(goodB2G1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UINT_MAX)
        {
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

static void goodB2G1()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    goodB2G1Static = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
static void goodB2G2Sink(unsigned int data)
{
    if(goodB2G2Static)
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < UINT_MAX)
        {
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

static void goodB2G2()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    goodB2G2Static = 1; /* true */
    goodB2G2Sink(data);
}

/* goodG2B() - use goodsource and badsink */
static void goodG2BSink(unsigned int data)
{
    if(goodG2BStatic)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}

static void goodG2B()
{
    unsigned int data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    goodG2BStatic = 1; /* true */
    goodG2BSink(data);
}

void CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_21_good()
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
    CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_21_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_21_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
