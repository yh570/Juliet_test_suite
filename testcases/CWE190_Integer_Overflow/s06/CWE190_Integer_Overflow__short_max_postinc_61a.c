/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_postinc_61a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
short CWE190_Integer_Overflow__short_max_postinc_61b_badSource(short data);

void CWE190_Integer_Overflow__short_max_postinc_61_bad()
{
    short data;
    data = 0;
    data = CWE190_Integer_Overflow__short_max_postinc_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        short result = data;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
short CWE190_Integer_Overflow__short_max_postinc_61b_goodG2BSource(short data);

static void goodG2B()
{
    short data;
    data = 0;
    data = CWE190_Integer_Overflow__short_max_postinc_61b_goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        short result = data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
short CWE190_Integer_Overflow__short_max_postinc_61b_goodB2GSource(short data);

static void goodB2G()
{
    short data;
    data = 0;
    data = CWE190_Integer_Overflow__short_max_postinc_61b_goodB2GSource(data);
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < SHRT_MAX)
    {
        data++;
        short result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

void CWE190_Integer_Overflow__short_max_postinc_61_good()
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
    CWE190_Integer_Overflow__short_max_postinc_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__short_max_postinc_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
