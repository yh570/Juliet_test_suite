/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_67a.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE369_Divide_by_Zero__int_zero_modulo_67_structType
{
    int structFirst;
} CWE369_Divide_by_Zero__int_zero_modulo_67_structType;


/* bad function declaration */
void CWE369_Divide_by_Zero__int_zero_modulo_67b_badSink(CWE369_Divide_by_Zero__int_zero_modulo_67_structType myStruct);

void CWE369_Divide_by_Zero__int_zero_modulo_67_bad()
{
    int data;
    CWE369_Divide_by_Zero__int_zero_modulo_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0;
    myStruct.structFirst = data;
    CWE369_Divide_by_Zero__int_zero_modulo_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_zero_modulo_67b_goodG2BSink(CWE369_Divide_by_Zero__int_zero_modulo_67_structType myStruct);

static void goodG2B()
{
    int data;
    CWE369_Divide_by_Zero__int_zero_modulo_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    myStruct.structFirst = data;
    CWE369_Divide_by_Zero__int_zero_modulo_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_zero_modulo_67b_goodB2GSink(CWE369_Divide_by_Zero__int_zero_modulo_67_structType myStruct);

static void goodB2G()
{
    int data;
    CWE369_Divide_by_Zero__int_zero_modulo_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0;
    myStruct.structFirst = data;
    CWE369_Divide_by_Zero__int_zero_modulo_67b_goodB2GSink(myStruct);
}

void CWE369_Divide_by_Zero__int_zero_modulo_67_good()
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
    CWE369_Divide_by_Zero__int_zero_modulo_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_zero_modulo_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
