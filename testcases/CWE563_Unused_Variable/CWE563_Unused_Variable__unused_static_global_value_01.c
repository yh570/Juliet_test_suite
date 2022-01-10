/*
 * @description Unused static global value
 * 
 * */

#include "std_testcase.h"


static int staticGlobalBad = 0;

void CWE563_Unused_Variable__unused_static_global_value_01_bad() 
{
    /* FLAW: Overwrite the initial value of the static global variable before use */
    staticGlobalBad = 10;
    printIntLine(staticGlobalBad);
}



static int staticGlobalGood1 = 5;

static void good1() 
{
    /* FIX: Do not overwrite the value of the static global variable before use */
    printIntLine(staticGlobalGood1);
}

void CWE563_Unused_Variable__unused_static_global_value_01_good() 
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
    CWE563_Unused_Variable__unused_static_global_value_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_static_global_value_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif