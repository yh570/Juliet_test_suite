/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_01.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


void CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_01_bad()
{
    int * data;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int) */
    data = (int *)ALLOCA(10);
    {
        int source[10] = {0};
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        memmove(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int) */
    data = (int *)ALLOCA(10*sizeof(int));
    {
        int source[10] = {0};
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        memmove(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_01_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
