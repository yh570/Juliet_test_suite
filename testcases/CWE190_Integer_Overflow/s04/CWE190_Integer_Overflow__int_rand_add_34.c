/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_add_34.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int unionFirst;
    int unionSecond;
} CWE190_Integer_Overflow__int_rand_add_34_unionType;


void CWE190_Integer_Overflow__int_rand_add_34_bad()
{
    int data;
    CWE190_Integer_Overflow__int_rand_add_34_unionType myUnion;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int result = data + 1;
            printIntLine(result);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    CWE190_Integer_Overflow__int_rand_add_34_unionType myUnion;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int result = data + 1;
            printIntLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    CWE190_Integer_Overflow__int_rand_add_34_unionType myUnion;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < INT_MAX)
        {
            int result = data + 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__int_rand_add_34_good()
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
    CWE190_Integer_Overflow__int_rand_add_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_rand_add_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
