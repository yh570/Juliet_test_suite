/*
 * @description Uncontrolled Recursion
 *
 * */

#include "std_testcase.h"


static void helperBad()
{
    /* FLAW: this function causes infinite recursion */
    helperBad(); /* maintenance note: this may generate a warning, this is on purpose */
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_bad()
{
    helperBad();
}



static void helperGood(unsigned level)
{
    /* FIX: provide lower-bound for recurssion stop */
    if (level == 0) 
    {
        return;
    }

    helperGood(level - 1);
}

static void good1()
{
    helperGood(5);
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_good()
{
    good1();
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
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
