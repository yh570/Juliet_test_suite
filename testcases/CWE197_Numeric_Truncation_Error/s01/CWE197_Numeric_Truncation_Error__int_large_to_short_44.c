/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_short_44.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"


static void badSink(int data)
{
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}

void CWE197_Numeric_Truncation_Error__int_large_to_short_44_bad()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = badSink;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a number larger than SHRT_MAX */
    data = SHRT_MAX + 5;
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(int data)
{
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short shortData = (short)data;
        printShortLine(shortData);
    }
}

static void goodG2B()
{
    int data;
    void (*funcPtr) (int) = goodG2BSink;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    funcPtr(data);
}

void CWE197_Numeric_Truncation_Error__int_large_to_short_44_good()
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
    CWE197_Numeric_Truncation_Error__int_large_to_short_44_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_large_to_short_44_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
