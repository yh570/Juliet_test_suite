/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_postinc_61b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


char CWE190_Integer_Overflow__char_rand_postinc_61b_badSource(char data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    return data;
}



/* goodG2B() uses the GoodSource with the BadSink */
char CWE190_Integer_Overflow__char_rand_postinc_61b_goodG2BSource(char data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
char CWE190_Integer_Overflow__char_rand_postinc_61b_goodB2GSource(char data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    return data;
}

