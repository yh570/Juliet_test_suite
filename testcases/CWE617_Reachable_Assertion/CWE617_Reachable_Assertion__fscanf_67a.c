/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_67a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

typedef struct _CWE617_Reachable_Assertion__fscanf_67_structType
{
    int structFirst;
} CWE617_Reachable_Assertion__fscanf_67_structType;


/* bad function declaration */
void CWE617_Reachable_Assertion__fscanf_67b_badSink(CWE617_Reachable_Assertion__fscanf_67_structType myStruct);

void CWE617_Reachable_Assertion__fscanf_67_bad()
{
    int data;
    CWE617_Reachable_Assertion__fscanf_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    myStruct.structFirst = data;
    CWE617_Reachable_Assertion__fscanf_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fscanf_67b_goodG2BSink(CWE617_Reachable_Assertion__fscanf_67_structType myStruct);

static void goodG2B()
{
    int data;
    CWE617_Reachable_Assertion__fscanf_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    myStruct.structFirst = data;
    CWE617_Reachable_Assertion__fscanf_67b_goodG2BSink(myStruct);
}

void CWE617_Reachable_Assertion__fscanf_67_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE617_Reachable_Assertion__fscanf_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__fscanf_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
