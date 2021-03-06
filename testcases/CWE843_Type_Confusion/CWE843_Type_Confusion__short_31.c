/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_31.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sinks:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"


void CWE843_Type_Confusion__short_31_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a short */
        short shortBuffer = 8;
        data = &shortBuffer;
    }
    {
        void * dataCopy = data;
        void * data = dataCopy;
        /* POTENTIAL FLAW: Attempt to access data as an int */
        printIntLine(*((int*)data));
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
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
    {
        void * dataCopy = data;
        void * data = dataCopy;
        /* POTENTIAL FLAW: Attempt to access data as an int */
        printIntLine(*((int*)data));
    }
}

void CWE843_Type_Confusion__short_31_good()
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
    CWE843_Type_Confusion__short_31_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__short_31_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
