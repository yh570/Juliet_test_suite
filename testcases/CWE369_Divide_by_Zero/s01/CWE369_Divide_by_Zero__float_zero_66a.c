/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_66a.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


/* bad function declaration */
void CWE369_Divide_by_Zero__float_zero_66b_badSink(float dataArray[]);

void CWE369_Divide_by_Zero__float_zero_66_bad()
{
    float data;
    float dataArray[5];
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
    /* put data in array */
    dataArray[2] = data;
    CWE369_Divide_by_Zero__float_zero_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__float_zero_66b_goodG2BSink(float dataArray[]);

static void goodG2B()
{
    float data;
    float dataArray[5];
    /* Initialize data */
    data = 0.0F;
    /* FIX: Use a hardcoded number that won't a divide by zero */
    data = 2.0F;
    dataArray[2] = data;
    CWE369_Divide_by_Zero__float_zero_66b_goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__float_zero_66b_goodB2GSink(float dataArray[]);

static void goodB2G()
{
    float data;
    float dataArray[5];
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
    dataArray[2] = data;
    CWE369_Divide_by_Zero__float_zero_66b_goodB2GSink(dataArray);
}

void CWE369_Divide_by_Zero__float_zero_66_good()
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
    CWE369_Divide_by_Zero__float_zero_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__float_zero_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
