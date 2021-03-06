/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_min_predec_45.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for unsigned int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static unsigned int CWE191_Integer_Underflow__unsigned_int_min_predec_45_badData;
static unsigned int CWE191_Integer_Underflow__unsigned_int_min_predec_45_goodG2BData;
static unsigned int CWE191_Integer_Underflow__unsigned_int_min_predec_45_goodB2GData;


static void badSink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_min_predec_45_badData;
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

void CWE191_Integer_Underflow__unsigned_int_min_predec_45_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = 0;
    CWE191_Integer_Underflow__unsigned_int_min_predec_45_badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_min_predec_45_goodG2BData;
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

static void goodG2B()
{
    unsigned int data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__unsigned_int_min_predec_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_min_predec_45_goodB2GData;
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > 0)
    {
        --data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

static void goodB2G()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = 0;
    CWE191_Integer_Underflow__unsigned_int_min_predec_45_goodB2GData = data;
    goodB2GSink();
}

void CWE191_Integer_Underflow__unsigned_int_min_predec_45_good()
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
    CWE191_Integer_Underflow__unsigned_int_min_predec_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__unsigned_int_min_predec_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
