/*
 * @description Expression is always false via if (unsigned int < 0)
 * 
 * */

#include "std_testcase.h"


void CWE570_Expression_Always_False__unsigned_int_01_bad() 
{
    /* Ensure (0 <= uIntBad < UINT_MAX) and that uIntBad is pseudo-random */
    unsigned int uIntBad = (unsigned int)(rand() * 2);

    /* FLAW: This expression is always false */
    if (uIntBad < 0) 
    {
        printLine("Never prints");
    }
}




static void good1() 
{
    int intGood = rand();

    /* FIX: Possibly evaluate to true */
    if (intGood < (RAND_MAX / 2)) 
    {
        printLine("Sometimes prints");
    }
}

void CWE570_Expression_Always_False__unsigned_int_01_good() 
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
    CWE570_Expression_Always_False__unsigned_int_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE570_Expression_Always_False__unsigned_int_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
