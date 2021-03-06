/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_square_67a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef struct _CWE190_Integer_Overflow__int_max_square_67_structType
{
    int structFirst;
} CWE190_Integer_Overflow__int_max_square_67_structType;


/* bad function declaration */
void CWE190_Integer_Overflow__int_max_square_67b_badSink(CWE190_Integer_Overflow__int_max_square_67_structType myStruct);

void CWE190_Integer_Overflow__int_max_square_67_bad()
{
    int data;
    CWE190_Integer_Overflow__int_max_square_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__int_max_square_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_max_square_67b_goodG2BSink(CWE190_Integer_Overflow__int_max_square_67_structType myStruct);

static void goodG2B()
{
    int data;
    CWE190_Integer_Overflow__int_max_square_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__int_max_square_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_max_square_67b_goodB2GSink(CWE190_Integer_Overflow__int_max_square_67_structType myStruct);

static void goodB2G()
{
    int data;
    CWE190_Integer_Overflow__int_max_square_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__int_max_square_67b_goodB2GSink(myStruct);
}

void CWE190_Integer_Overflow__int_max_square_67_good()
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
    CWE190_Integer_Overflow__int_max_square_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_max_square_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
