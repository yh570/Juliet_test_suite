/*
 * @description Undefined Behavior - Missing Return Value From Function
 * 
 * */

#include "std_testcase.h"


static int helperBad(void)
{
    /* FLAW: no return in a function with an explicit return type of int */
}

void CWE758_Undefined_Behavior__no_return_01_bad() 
{
    int intBad = helperBad();
    printIntLine(intBad);
}




static int helperGood1(void)
{
    /* FIX: return a value */
    return 5;
}

static void good1() 
{
    int intGood1 = helperGood1();
    printIntLine(intGood1);
}

void CWE758_Undefined_Behavior__no_return_01_good() 
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
    CWE758_Undefined_Behavior__no_return_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__no_return_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif