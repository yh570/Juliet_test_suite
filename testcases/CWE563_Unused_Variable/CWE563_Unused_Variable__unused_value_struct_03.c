/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_03.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE563_Unused_Variable__unused_value_struct_03_bad()
{
    twoIntsStruct data;
    if(5==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.intOne = 0;
        data.intTwo = 0;
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second 5==5 to 5!=5 */
static void goodB2G1()
{
    twoIntsStruct data;
    if(5==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.intOne = 0;
        data.intTwo = 0;
    }
    if(5!=5)
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

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoIntsStruct data;
    if(5==5)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.intOne = 0;
        data.intTwo = 0;
    }
    if(5==5)
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 5==5 to 5!=5 */
static void goodG2B1()
{
    twoIntsStruct data;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize and use data before it is overwritten */
        data.intOne = 0;
        data.intTwo = 0;
        printStructLine(&data);
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoIntsStruct data;
    if(5==5)
    {
        /* FIX: Initialize and use data before it is overwritten */
        data.intOne = 0;
        data.intTwo = 0;
        printStructLine(&data);
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

void CWE563_Unused_Variable__unused_value_struct_03_good()
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
    CWE563_Unused_Variable__unused_value_struct_03_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_struct_03_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
