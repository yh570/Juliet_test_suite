/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_21.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(twoIntsStruct data)
{
    if(badStatic)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

void CWE563_Unused_Variable__unused_value_struct_21_bad()
{
    twoIntsStruct data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
    badStatic = 1; /* true */
    badSink(data);
}



/* The static variables below are used to drive control flow in the sink functions. */
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
static void goodB2G1Sink(twoIntsStruct data)
{
    if(goodB2G1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

static void goodB2G1()
{
    twoIntsStruct data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
    goodB2G1Static = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
static void goodB2G2Sink(twoIntsStruct data)
{
    if(goodB2G2Static)
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

static void goodB2G2()
{
    twoIntsStruct data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data.intOne = 0;
    data.intTwo = 0;
    goodB2G2Static = 1; /* true */
    goodB2G2Sink(data);
}

/* goodG2B() - use goodsource and badsink */
static void goodG2BSink(twoIntsStruct data)
{
    if(goodG2BStatic)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

static void goodG2B()
{
    twoIntsStruct data;
    /* FIX: Initialize and use data before it is overwritten */
    data.intOne = 0;
    data.intTwo = 0;
    printStructLine(&data);
    goodG2BStatic = 1; /* true */
    goodG2BSink(data);
}

void CWE563_Unused_Variable__unused_value_struct_21_good()
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
    CWE563_Unused_Variable__unused_value_struct_21_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_struct_21_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
