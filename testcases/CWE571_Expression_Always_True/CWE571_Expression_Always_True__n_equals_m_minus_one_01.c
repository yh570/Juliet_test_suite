/*
 * @description Expression is always true via if (true_expression)
 * 
 * */

#include "std_testcase.h"


void CWE571_Expression_Always_True__n_equals_m_minus_one_01_bad() 
{
    int intRand1 = 30;
    int intRand2 = 31;

    /* FLAW: This expression is always true */
    if (intRand1 == (intRand2 - 1)) 
    {
        printLine("Always prints");
    }
}




static void good1() 
{
    /* INCIDENTAL: CWE 338 - Use of Cryptographically Weak PRNG */
    int intRand1 = rand();
    int intRand2 = rand();

    /* FIX: Possibly evaluate to false */
    if(intRand1 != intRand2)
	{
        printLine("Sometimes prints");
    }
}

void CWE571_Expression_Always_True__n_equals_m_minus_one_01_good() 
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
    CWE571_Expression_Always_True__n_equals_m_minus_one_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE571_Expression_Always_True__n_equals_m_minus_one_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
