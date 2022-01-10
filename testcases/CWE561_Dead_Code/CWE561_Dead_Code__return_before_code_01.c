/*
 * @description Unused code via 'return' before code
 * 
 * */

#include "std_testcase.h"


void CWE561_Dead_Code__return_before_code_01_bad() 
{
    return;
    /* FLAW: code after the 'return' */
    printLine("Hello");
}



static void good1() 
{
    /* FIX: Put code prior to return, or omit it */
    printLine("Hello");
    return;
}

void CWE561_Dead_Code__return_before_code_01_good() 
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
    CWE561_Dead_Code__return_before_code_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE561_Dead_Code__return_before_code_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
