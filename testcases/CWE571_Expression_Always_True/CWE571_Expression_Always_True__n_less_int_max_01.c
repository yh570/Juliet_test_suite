/*
 * @description Expression is always true via if (true_expression)
 * 
 * */

#include "std_testcase.h"


void CWE571_Expression_Always_True__n_less_int_max_01_bad() 
{
    /* INCIDENTAL: CWE 338 - Use of Cryptographically Weak PRNG */
    int intRand = rand();

    /* FLAW: This expression is always true */
    if (intRand <= INT_MAX) 
    {
        printLine("Always prints");
    }
}




static void good1() 
{
    /* INCIDENTAL: CWE 338 - Use of Cryptographically Weak PRNG */
    int intRand = rand();

    /* FIX: Possibly evaluate to false */
    if(intRand < 5000)
    {
        printLine("Sometimes prints");
    }
}

void CWE571_Expression_Always_True__n_less_int_max_01_good() 
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
    CWE571_Expression_Always_True__n_less_int_max_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE571_Expression_Always_True__n_less_int_max_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
