/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_65a.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sinks:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE843_Type_Confusion__char_65b_badSink(void * data);

void CWE843_Type_Confusion__char_65_bad()
{
    void * data;
    /* define a function pointer */
    void (*funcPtr) (void *) = CWE843_Type_Confusion__char_65b_badSink;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a char */
        char charBuffer = 'a';
        data = &charBuffer;
    }
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE843_Type_Confusion__char_65b_goodG2BSink(void * data);

static void goodG2B()
{
    void * data;
    void (*funcPtr) (void *) = CWE843_Type_Confusion__char_65b_goodG2BSink;
    /* Initialize data */
    data = NULL;
    {
        /* FIX: Point data to an int */
        int intBuffer = 8;
        data = &intBuffer;
    }
    funcPtr(data);
}

void CWE843_Type_Confusion__char_65_good()
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
    CWE843_Type_Confusion__char_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE843_Type_Confusion__char_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
