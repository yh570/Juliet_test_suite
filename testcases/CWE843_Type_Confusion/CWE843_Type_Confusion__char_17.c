/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_17.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


void CWE843_Type_Confusion__char_17_bad()
{
    int i;
    void * data;
    /* Initialize data */
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        {
            /* FLAW: Point data to a char */
            char charBuffer = 'a';
            data = &charBuffer;
        }
    }
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}



/* goodG2B() - use goodsource and badsink by changing the conditions on the for statements */
static void goodG2B()
{
    int h;
    void * data;
    /* Initialize data */
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        {
            /* FIX: Point data to an int */
            int intBuffer = 8;
            data = &intBuffer;
        }
    }
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

void CWE843_Type_Confusion__char_17_good()
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
    CWE843_Type_Confusion__char_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__char_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
