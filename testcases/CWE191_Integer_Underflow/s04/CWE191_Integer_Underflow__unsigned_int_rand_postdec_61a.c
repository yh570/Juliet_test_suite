/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_rand_postdec_61a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
unsigned int CWE191_Integer_Underflow__unsigned_int_rand_postdec_61b_badSource(unsigned int data);

void CWE191_Integer_Underflow__unsigned_int_rand_postdec_61_bad()
{
    unsigned int data;
    data = 0;
    data = CWE191_Integer_Underflow__unsigned_int_rand_postdec_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
unsigned int CWE191_Integer_Underflow__unsigned_int_rand_postdec_61b_goodG2BSource(unsigned int data);

static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = CWE191_Integer_Underflow__unsigned_int_rand_postdec_61b_goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
unsigned int CWE191_Integer_Underflow__unsigned_int_rand_postdec_61b_goodB2GSource(unsigned int data);

static void goodB2G()
{
    unsigned int data;
    data = 0;
    data = CWE191_Integer_Underflow__unsigned_int_rand_postdec_61b_goodB2GSource(data);
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > 0)
    {
        data--;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

void CWE191_Integer_Underflow__unsigned_int_rand_postdec_61_good()
{
    goodG2B();
    goodB2G();
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
    CWE191_Integer_Underflow__unsigned_int_rand_postdec_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_int_rand_postdec_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
