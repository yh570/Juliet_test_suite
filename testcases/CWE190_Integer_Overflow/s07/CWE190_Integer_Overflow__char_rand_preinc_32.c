/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_preinc_32.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


void CWE190_Integer_Overflow__char_rand_preinc_32_bad()
{
    char data;
    char *dataPtr1 = &data;
    char *dataPtr2 = &data;
    data = ' ';
    {
        char data = *dataPtr1;
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
        *dataPtr1 = data;
    }
    {
        char data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            ++data;
            char result = data;
            printHexCharLine(result);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    char *dataPtr1 = &data;
    char *dataPtr2 = &data;
    data = ' ';
    {
        char data = *dataPtr1;
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
        *dataPtr1 = data;
    }
    {
        char data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            ++data;
            char result = data;
            printHexCharLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char data;
    char *dataPtr1 = &data;
    char *dataPtr2 = &data;
    data = ' ';
    {
        char data = *dataPtr1;
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
        *dataPtr1 = data;
    }
    {
        char data = *dataPtr2;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < CHAR_MAX)
        {
            ++data;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__char_rand_preinc_32_good()
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
    CWE190_Integer_Overflow__char_rand_preinc_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_preinc_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
