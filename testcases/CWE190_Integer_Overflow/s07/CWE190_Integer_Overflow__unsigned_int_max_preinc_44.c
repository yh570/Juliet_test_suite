/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_preinc_44.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"


static void badSink(unsigned int data)
{
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_preinc_44_bad()
{
    unsigned int data;
    /* define a function pointer */
    void (*funcPtr) (unsigned int) = badSink;
    data = 0;
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(unsigned int data)
{
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

static void goodG2B()
{
    unsigned int data;
    void (*funcPtr) (unsigned int) = goodG2BSink;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    funcPtr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink(unsigned int data)
{
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

static void goodB2G()
{
    unsigned int data;
    void (*funcPtr) (unsigned int) = goodB2GSink;
    data = 0;
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
    funcPtr(data);
}

void CWE190_Integer_Overflow__unsigned_int_max_preinc_44_good()
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
    CWE190_Integer_Overflow__unsigned_int_max_preinc_44_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_max_preinc_44_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
