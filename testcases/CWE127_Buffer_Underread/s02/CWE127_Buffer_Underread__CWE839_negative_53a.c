/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_negative_53a.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: negative Negative index value
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE127_Buffer_Underread__CWE839_negative_53b_badSink(int data);

void CWE127_Buffer_Underread__CWE839_negative_53_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = -5;
    CWE127_Buffer_Underread__CWE839_negative_53b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__CWE839_negative_53b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE127_Buffer_Underread__CWE839_negative_53b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE127_Buffer_Underread__CWE839_negative_53b_goodB2GSink(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = -5;
    CWE127_Buffer_Underread__CWE839_negative_53b_goodB2GSink(data);
}

void CWE127_Buffer_Underread__CWE839_negative_53_good()
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
    CWE127_Buffer_Underread__CWE839_negative_53_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__CWE839_negative_53_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
