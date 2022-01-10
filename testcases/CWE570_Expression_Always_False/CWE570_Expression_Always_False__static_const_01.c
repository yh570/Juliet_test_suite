/*
 * @description Expression is always false via if (false_expression)
 * 
 * */

#include "std_testcase.h"

static const int STATIC_CONST_FALSE = 0; /* false */


void CWE570_Expression_Always_False__static_const_01_bad() 
{
    /* FLAW: This expression is always false */
    if (STATIC_CONST_FALSE) 
    {
        printLine("Never prints");
    }
}




static void good1() 
{
    /* FIX: Possibly evaluate to true */
    if (globalReturnsTrueOrFalse() == STATIC_CONST_FALSE)
    {
        printLine("Sometimes prints");
    }
}

void CWE570_Expression_Always_False__static_const_01_good() 
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
    CWE570_Expression_Always_False__static_const_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE570_Expression_Always_False__static_const_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
