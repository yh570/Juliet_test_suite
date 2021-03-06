/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_rand_modulo_65a.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE369_Divide_by_Zero__int_rand_modulo_65b_badSink(int data);

void CWE369_Divide_by_Zero__int_rand_modulo_65_bad()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = CWE369_Divide_by_Zero__int_rand_modulo_65b_badSink;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_rand_modulo_65b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    void (*funcPtr) (int) = CWE369_Divide_by_Zero__int_rand_modulo_65b_goodG2BSink;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_rand_modulo_65b_goodB2GSink(int data);

static void goodB2G()
{
    int data;
    void (*funcPtr) (int) = CWE369_Divide_by_Zero__int_rand_modulo_65b_goodB2GSink;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    funcPtr(data);
}

void CWE369_Divide_by_Zero__int_rand_modulo_65_good()
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
    CWE369_Divide_by_Zero__int_rand_modulo_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_rand_modulo_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
