/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE482_Comparing_Instead_of_Assigning__basic_18.c
Label Definition File: CWE482_Comparing_Instead_of_Assigning__basic.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 482 Comparing Instead of Assigning
 * Sinks:
 *    GoodSink: Assigning
 *    BadSink : Comparing instead of assigning
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE482_Comparing_Instead_of_Assigning__basic_18_bad()
{
    goto sink;
sink:
    {
        int intBadSink = 0;
        /* Print original value to avoid any unused variable incidentals */
        printIntLine(intBadSink);
        /* FLAW: meant to assign 5 to intBadSink.  Maintenance note: may generate a compiler warning, this is intentional */
        intBadSink == 5;
        printIntLine(intBadSink);
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        int intGoodSink = 0;
        /* Print original value to avoid any unused variable incidentals */
        printIntLine(intGoodSink);
        /* FIX: use = instead of == */
        intGoodSink = 5;
        printIntLine(intGoodSink);
    }
}

void CWE482_Comparing_Instead_of_Assigning__basic_18_good()
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
    CWE482_Comparing_Instead_of_Assigning__basic_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE482_Comparing_Instead_of_Assigning__basic_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
