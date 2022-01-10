/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_68a.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

void * CWE843_Type_Confusion__short_68_badData;
void * CWE843_Type_Confusion__short_68_goodG2BData;


/* bad function declaration */
void CWE843_Type_Confusion__short_68b_badSink();

void CWE843_Type_Confusion__short_68_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a short */
        short shortBuffer = 8;
        data = &shortBuffer;
    }
    CWE843_Type_Confusion__short_68_badData = data;
    CWE843_Type_Confusion__short_68b_badSink();
}



/* good function declarations */
void CWE843_Type_Confusion__short_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
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
    CWE843_Type_Confusion__short_68_goodG2BData = data;
    CWE843_Type_Confusion__short_68b_goodG2BSink();
}

void CWE843_Type_Confusion__short_68_good()
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
    CWE843_Type_Confusion__short_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__short_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
