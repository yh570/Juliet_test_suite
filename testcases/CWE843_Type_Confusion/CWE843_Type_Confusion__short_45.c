/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_45.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sinks:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static void * CWE843_Type_Confusion__short_45_badData;
static void * CWE843_Type_Confusion__short_45_goodG2BData;


static void badSink()
{
    void * data = CWE843_Type_Confusion__short_45_badData;
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

void CWE843_Type_Confusion__short_45_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a short */
        short shortBuffer = 8;
        data = &shortBuffer;
    }
    CWE843_Type_Confusion__short_45_badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    void * data = CWE843_Type_Confusion__short_45_goodG2BData;
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

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
    CWE843_Type_Confusion__short_45_goodG2BData = data;
    goodG2BSink();
}

void CWE843_Type_Confusion__short_45_good()
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
    CWE843_Type_Confusion__short_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__short_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
