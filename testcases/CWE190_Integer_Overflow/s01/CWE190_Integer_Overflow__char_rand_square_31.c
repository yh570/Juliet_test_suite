/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_square_31.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-31.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <math.h>


void CWE190_Integer_Overflow__char_rand_square_31_bad()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    {
        char dataCopy = data;
        char data = dataCopy;
        {
            /* POTENTIAL FLAW: if (data*data) > CHAR_MAX, this will overflow */
            char result = data * data;
            printHexCharLine(result);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    {
        char dataCopy = data;
        char data = dataCopy;
        {
            /* POTENTIAL FLAW: if (data*data) > CHAR_MAX, this will overflow */
            char result = data * data;
            printHexCharLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    {
        char dataCopy = data;
        char data = dataCopy;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (abs((long)data) <= (long)sqrt((double)CHAR_MAX))
        {
            char result = data * data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__char_rand_square_31_good()
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
    CWE190_Integer_Overflow__char_rand_square_31_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_square_31_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
