/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_postinc_63b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__char_rand_postinc_63b_badSink(char * dataPtr)
{
    char data = *dataPtr;
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        char result = data;
        printHexCharLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_postinc_63b_goodG2BSink(char * dataPtr)
{
    char data = *dataPtr;
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        char result = data;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_postinc_63b_goodB2GSink(char * dataPtr)
{
    char data = *dataPtr;
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

