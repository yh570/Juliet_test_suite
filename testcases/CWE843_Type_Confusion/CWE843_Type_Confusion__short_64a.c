/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_64a.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sinks:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE843_Type_Confusion__short_64b_badSink(void * dataVoidPtr);

void CWE843_Type_Confusion__short_64_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a short */
        short shortBuffer = 8;
        data = &shortBuffer;
    }
    CWE843_Type_Confusion__short_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE843_Type_Confusion__short_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FIX: Point data to an int */
        int intBuffer = 8;
        data = &intBuffer;
    }
    CWE843_Type_Confusion__short_64b_goodG2BSink(&data);
}

void CWE843_Type_Confusion__short_64_good()
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
    CWE843_Type_Confusion__short_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__short_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
