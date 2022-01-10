/*
 * @description Unused global variable
 * 
 * */

#include "std_testcase.h"


int CWE563_Unused_Variable__unused_global_variable_01_globalBad = 0;

void CWE563_Unused_Variable__unused_global_variable_01_bad() 
{
    /* FLAW: Do not use the global variable */
    printLine("This function does not use the global variable: CWE563_Unused_Variable__unused_global_variable_01_globalBad.");
}



int CWE563_Unused_Variable__unused_global_variable_01_globalGood1 = 5;

static void good1() 
{
    /* FIX: Use the global variable */
    printIntLine(CWE563_Unused_Variable__unused_global_variable_01_globalGood1);
}

void CWE563_Unused_Variable__unused_global_variable_01_good() 
{
    good1();
}


/* Below is the main(). It is only used when building this testcase on 
 *  its own for testing or for building a binary to use in testing binary 
 *  analysis tools. It is not used when compiling all the testcases as one 
 *  application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) 
{
    /* seed randomness */

    printLine("Calling good()...");
    CWE563_Unused_Variable__unused_global_variable_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_global_variable_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif