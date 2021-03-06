/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_rand_modulo_53b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE369_Divide_by_Zero__int_rand_modulo_53c_badSink(int data);

void CWE369_Divide_by_Zero__int_rand_modulo_53b_badSink(int data)
{
    CWE369_Divide_by_Zero__int_rand_modulo_53c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_rand_modulo_53c_goodG2BSink(int data);

void CWE369_Divide_by_Zero__int_rand_modulo_53b_goodG2BSink(int data)
{
    CWE369_Divide_by_Zero__int_rand_modulo_53c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_rand_modulo_53c_goodB2GSink(int data);

void CWE369_Divide_by_Zero__int_rand_modulo_53b_goodB2GSink(int data)
{
    CWE369_Divide_by_Zero__int_rand_modulo_53c_goodB2GSink(data);
}

