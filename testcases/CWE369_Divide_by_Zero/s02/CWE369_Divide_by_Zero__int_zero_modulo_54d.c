/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_54d.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE369_Divide_by_Zero__int_zero_modulo_54e_badSink(int data);

void CWE369_Divide_by_Zero__int_zero_modulo_54d_badSink(int data)
{
    CWE369_Divide_by_Zero__int_zero_modulo_54e_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_zero_modulo_54e_goodG2BSink(int data);

void CWE369_Divide_by_Zero__int_zero_modulo_54d_goodG2BSink(int data)
{
    CWE369_Divide_by_Zero__int_zero_modulo_54e_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_zero_modulo_54e_goodB2GSink(int data);

void CWE369_Divide_by_Zero__int_zero_modulo_54d_goodB2GSink(int data)
{
    CWE369_Divide_by_Zero__int_zero_modulo_54e_goodB2GSink(data);
}

