/*
 * @description Uncontrolled Recursion
 *
 * */

#include "std_testcase.h"


static void helperBad(unsigned level)
{
    /* FLAW: Although this cannot cause "infinite" recursion, it is essentially limited to UINT_MAX
     * which is rather large on most systems */
    if (level == 0) 
    {
        return;
    }

    helperBad(level - 1);
}

void CWE674_Uncontrolled_Recursion__unbounded_recursive_call_01_bad()
{
    helperBad(UINT_MAX);
}



#define MAX_RECURSION 10

static void helperGood(unsigned level)
{
    /* FIX: limit recursion to a sane level */
    if (level > MAX_RECURSION) 
    {
        printLine("ERROR IN RECURSION");
        return;
    }

    if (level == 0) 
    {
        return;
    }

    helperGood(level - 1);
}

static void good1()
{
    helperGood(UINT_MAX);
}

void CWE674_Uncontrolled_Recursion__unbounded_recursive_call_01_good()
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
    CWE674_Uncontrolled_Recursion__unbounded_recursive_call_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE674_Uncontrolled_Recursion__unbounded_recursive_call_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
