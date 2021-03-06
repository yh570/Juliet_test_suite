/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int unionFirst;
    int unionSecond;
} CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_unionType;


void CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_bad()
{
    int data;
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_unionType myUnion;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
            short shortData = (short)data;
            printShortLine(shortData);
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_unionType myUnion;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
            short shortData = (short)data;
            printShortLine(shortData);
        }
    }
}

void CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_good()
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
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_fscanf_to_short_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
