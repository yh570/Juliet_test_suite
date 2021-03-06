/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_postinc_51a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE190_Integer_Overflow__int_max_postinc_51b_badSink(int data);

void CWE190_Integer_Overflow__int_max_postinc_51_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_postinc_51b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_max_postinc_51b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__int_max_postinc_51b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_max_postinc_51b_goodB2GSink(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_postinc_51b_goodB2GSink(data);
}

void CWE190_Integer_Overflow__int_max_postinc_51_good()
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
    CWE190_Integer_Overflow__int_max_postinc_51_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_postinc_51_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
