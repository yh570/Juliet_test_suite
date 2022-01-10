/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_32.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


void CWE843_Type_Confusion__char_32_bad()
{
    void * data;
    void * *dataPtr1 = &data;
    void * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        void * data = *dataPtr1;
        {
            /* FLAW: Point data to a char */
            char charBuffer = 'a';
            data = &charBuffer;
        }
        *dataPtr1 = data;
    }
    {
        void * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to access data as an int */
        printIntLine(*((int*)data));
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    void * *dataPtr1 = &data;
    void * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        void * data = *dataPtr1;
        {
            /* FIX: Point data to an int */
            int intBuffer = 8;
            data = &intBuffer;
        }
        *dataPtr1 = data;
    }
    {
        void * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to access data as an int */
        printIntLine(*((int*)data));
    }
}

void CWE843_Type_Confusion__char_32_good()
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
    CWE843_Type_Confusion__char_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__char_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
