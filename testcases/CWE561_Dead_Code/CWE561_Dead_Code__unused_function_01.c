/*
 * @description Unused function declaration
 * 
 * */

#include "std_testcase.h"


/* FLAW: this function is never used (this should be easy for a tool to determine
 * because it is statically scoped and therefore cannot be accessed outside of this source file */
static void helperBad() 
{
    printLine("helperBad()");
}

void CWE561_Dead_Code__unused_function_01_bad() 
{
    printLine("CWE561_Dead_Code__unused_function_01_bad()");
}



/* FIX: this function is used */
static void helperGood1() 
{
    printLine("helperGood1()");
}

static void good1() 
{
    printLine("CWE561_Dead_Code__unused_function_01_good()");
    helperGood1();
}

void CWE561_Dead_Code__unused_function_01_good() 
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
    CWE561_Dead_Code__unused_function_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE561_Dead_Code__unused_function_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
