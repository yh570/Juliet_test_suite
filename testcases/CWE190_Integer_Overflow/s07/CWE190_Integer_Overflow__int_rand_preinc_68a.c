/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_preinc_68a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE190_Integer_Overflow__int_rand_preinc_68_badData;
int CWE190_Integer_Overflow__int_rand_preinc_68_goodG2BData;
int CWE190_Integer_Overflow__int_rand_preinc_68_goodB2GData;


/* bad function declaration */
void CWE190_Integer_Overflow__int_rand_preinc_68b_badSink();

void CWE190_Integer_Overflow__int_rand_preinc_68_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    CWE190_Integer_Overflow__int_rand_preinc_68_badData = data;
    CWE190_Integer_Overflow__int_rand_preinc_68b_badSink();
}



/* good function declarations */
void CWE190_Integer_Overflow__int_rand_preinc_68b_goodG2BSink();
void CWE190_Integer_Overflow__int_rand_preinc_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__int_rand_preinc_68_goodG2BData = data;
    CWE190_Integer_Overflow__int_rand_preinc_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    CWE190_Integer_Overflow__int_rand_preinc_68_goodB2GData = data;
    CWE190_Integer_Overflow__int_rand_preinc_68b_goodB2GSink();
}

void CWE190_Integer_Overflow__int_rand_preinc_68_good()
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
    CWE190_Integer_Overflow__int_rand_preinc_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_rand_preinc_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
