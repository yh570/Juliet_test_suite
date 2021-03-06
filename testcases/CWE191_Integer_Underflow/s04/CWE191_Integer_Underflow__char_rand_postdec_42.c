/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_rand_postdec_42.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"


static char badSource(char data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    return data;
}

void CWE191_Integer_Underflow__char_rand_postdec_42_bad()
{
    char data;
    data = ' ';
    data = badSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        char result = data;
        printHexCharLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
static char goodG2BSource(char data)
{
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    return data;
}

static void goodG2B()
{
    char data;
    data = ' ';
    data = goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        char result = data;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static char goodB2GSource(char data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    return data;
}

static void goodB2G()
{
    char data;
    data = ' ';
    data = goodB2GSource(data);
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > CHAR_MIN)
    {
        data--;
        char result = data;
        printHexCharLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

void CWE191_Integer_Underflow__char_rand_postdec_42_good()
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
    CWE191_Integer_Underflow__char_rand_postdec_42_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_rand_postdec_42_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
