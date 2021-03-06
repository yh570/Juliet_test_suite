/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_min_sub_67a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for char
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE191_Integer_Underflow__char_min_sub_67_structType
{
    char structFirst;
} CWE191_Integer_Underflow__char_min_sub_67_structType;


/* bad function declaration */
void CWE191_Integer_Underflow__char_min_sub_67b_badSink(CWE191_Integer_Underflow__char_min_sub_67_structType myStruct);

void CWE191_Integer_Underflow__char_min_sub_67_bad()
{
    char data;
    CWE191_Integer_Underflow__char_min_sub_67_structType myStruct;
    data = ' ';
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = CHAR_MIN;
    myStruct.structFirst = data;
    CWE191_Integer_Underflow__char_min_sub_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__char_min_sub_67b_goodG2BSink(CWE191_Integer_Underflow__char_min_sub_67_structType myStruct);

static void goodG2B()
{
    char data;
    CWE191_Integer_Underflow__char_min_sub_67_structType myStruct;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    myStruct.structFirst = data;
    CWE191_Integer_Underflow__char_min_sub_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__char_min_sub_67b_goodB2GSink(CWE191_Integer_Underflow__char_min_sub_67_structType myStruct);

static void goodB2G()
{
    char data;
    CWE191_Integer_Underflow__char_min_sub_67_structType myStruct;
    data = ' ';
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = CHAR_MIN;
    myStruct.structFirst = data;
    CWE191_Integer_Underflow__char_min_sub_67b_goodB2GSink(myStruct);
}

void CWE191_Integer_Underflow__char_min_sub_67_good()
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
    CWE191_Integer_Underflow__char_min_sub_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_min_sub_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
