/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_postinc_17.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__int_fscanf_postinc_17_bad()
{
    int i,j;
    int data;
    /* Initialize data */
    data = 0;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Read data from the console using fscanf() */
        fscanf(stdin, "%d", &data);
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            int result = data;
            printIntLine(result);
        }
    }
}



/* goodB2G() - use badsource and goodsink in the for statements */
static void goodB2G()
{
    int i,k;
    int data;
    /* Initialize data */
    data = 0;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Read data from the console using fscanf() */
        fscanf(stdin, "%d", &data);
    }
    for(k = 0; k < 1; k++)
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < INT_MAX)
        {
            data++;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B() - use goodsource and badsink in the for statements */
static void goodG2B()
{
    int h,j;
    int data;
    /* Initialize data */
    data = 0;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 2;
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            int result = data;
            printIntLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int_fscanf_postinc_17_good()
{
    goodB2G();
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
    CWE190_Integer_Overflow__int_fscanf_postinc_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_fscanf_postinc_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
