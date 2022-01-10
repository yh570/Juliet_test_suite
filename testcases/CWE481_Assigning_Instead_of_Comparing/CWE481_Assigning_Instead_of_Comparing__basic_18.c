/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE481_Assigning_Instead_of_Comparing__basic_18.c
Label Definition File: CWE481_Assigning_Instead_of_Comparing__basic.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 481 Assigning Instead of Comparing
 * Sinks:
 *    GoodSink: Comparing
 *    BadSink : Assigning instead of comparing
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE481_Assigning_Instead_of_Comparing__basic_18_bad()
{
    goto sink;
sink:
    {
        int intRand = rand();
        /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
        if(intRand = 5)
        {
            printLine("i was 5");
        }
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        int intRand = rand();
        /* FIX: used == instead of = */
        if(intRand == 5)
        {
            printLine("i was 5");
        }
    }
}

void CWE481_Assigning_Instead_of_Comparing__basic_18_good()
{
    good1();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE481_Assigning_Instead_of_Comparing__basic_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE481_Assigning_Instead_of_Comparing__basic_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
