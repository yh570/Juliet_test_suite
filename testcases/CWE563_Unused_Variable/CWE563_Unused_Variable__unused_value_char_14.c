/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_char_14.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE563_Unused_Variable__unused_value_char_14_bad()
{
    char data;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 'C';
    }
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 'Z';
        printHexCharLine(data);
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second globalFive==5 to globalFive!=5 */
static void goodB2G1()
{
    char data;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 'C';
    }
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data without over-writing its value */
        printHexCharLine(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char data;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 'C';
    }
    if(globalFive==5)
    {
        /* FIX: Use data without over-writing its value */
        printHexCharLine(data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first globalFive==5 to globalFive!=5 */
static void goodG2B1()
{
    char data;
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize and use data before it is overwritten */
        data = 'C';
        printHexCharLine(data);
    }
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 'Z';
        printHexCharLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char data;
    if(globalFive==5)
    {
        /* FIX: Initialize and use data before it is overwritten */
        data = 'C';
        printHexCharLine(data);
    }
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 'Z';
        printHexCharLine(data);
    }
}

void CWE563_Unused_Variable__unused_value_char_14_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE563_Unused_Variable__unused_value_char_14_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_char_14_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
