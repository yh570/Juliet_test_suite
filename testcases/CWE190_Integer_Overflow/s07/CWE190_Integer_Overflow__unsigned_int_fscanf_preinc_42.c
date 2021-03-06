/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_42.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"


static unsigned int badSource(unsigned int data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    return data;
}

void CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_42_bad()
{
    unsigned int data;
    data = 0;
    data = badSource(data);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
static unsigned int goodG2BSource(unsigned int data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    return data;
}

static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static unsigned int goodB2GSource(unsigned int data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%u", &data);
    return data;
}

static void goodB2G()
{
    unsigned int data;
    data = 0;
    data = goodB2GSource(data);
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < UINT_MAX)
    {
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

void CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_42_good()
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
    CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_42_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_42_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
