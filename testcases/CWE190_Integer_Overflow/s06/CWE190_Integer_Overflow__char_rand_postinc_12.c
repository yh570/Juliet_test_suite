/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_postinc_12.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__char_rand_postinc_12_bad()
{
    char data;
    data = ' ';
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
    else
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < CHAR_MAX)
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    char data;
    data = ' ';
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
    }
    else
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
    }
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < CHAR_MAX)
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
    else
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < CHAR_MAX)
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    char data;
    data = ' ';
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
    else
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
}

void CWE190_Integer_Overflow__char_rand_postinc_12_good()
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
    CWE190_Integer_Overflow__char_rand_postinc_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_postinc_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
