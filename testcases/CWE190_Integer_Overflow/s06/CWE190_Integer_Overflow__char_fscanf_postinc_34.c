/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_postinc_34.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    char unionFirst;
    char unionSecond;
} CWE190_Integer_Overflow__char_fscanf_postinc_34_unionType;


void CWE190_Integer_Overflow__char_fscanf_postinc_34_bad()
{
    char data;
    CWE190_Integer_Overflow__char_fscanf_postinc_34_unionType myUnion;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    myUnion.unionFirst = data;
    {
        char data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    CWE190_Integer_Overflow__char_fscanf_postinc_34_unionType myUnion;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    myUnion.unionFirst = data;
    {
        char data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char data;
    CWE190_Integer_Overflow__char_fscanf_postinc_34_unionType myUnion;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    myUnion.unionFirst = data;
    {
        char data = myUnion.unionSecond;
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
}

void CWE190_Integer_Overflow__char_fscanf_postinc_34_good()
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
    CWE190_Integer_Overflow__char_fscanf_postinc_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_fscanf_postinc_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
