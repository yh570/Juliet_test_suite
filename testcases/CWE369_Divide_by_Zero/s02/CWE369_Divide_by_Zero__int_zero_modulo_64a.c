/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_64a.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE369_Divide_by_Zero__int_zero_modulo_64b_badSink(void * dataVoidPtr);

void CWE369_Divide_by_Zero__int_zero_modulo_64_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0;
    CWE369_Divide_by_Zero__int_zero_modulo_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_zero_modulo_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    CWE369_Divide_by_Zero__int_zero_modulo_64b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_zero_modulo_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0;
    CWE369_Divide_by_Zero__int_zero_modulo_64b_goodB2GSink(&data);
}

void CWE369_Divide_by_Zero__int_zero_modulo_64_good()
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
    CWE369_Divide_by_Zero__int_zero_modulo_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_zero_modulo_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
