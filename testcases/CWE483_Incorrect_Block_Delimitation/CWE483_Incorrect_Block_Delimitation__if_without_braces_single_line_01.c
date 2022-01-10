/*
 * @description Incorrect Block Delimitation
 *
 * */

#include "std_testcase.h"


void CWE483_Incorrect_Block_Delimitation__if_without_braces_single_line_01_bad()
{
    int x,y;
    
    x = (rand() % 3);
    y = 0;
    
    /* FLAW: forgot to put these two statements within braces (on the same line) */
    if (x == 0) printLine("x == 0"); y = 1;
    
    if (y) 
    {
        printLine("x was 0\n");
    }
}



static void good1()
{
    int x,y;
    
    x = (rand() % 3);
    y = 0;
    
    /* FIX: put the related statements within braces */
    if (x == 0) 
    { 
        printLine("x == 0"); y = 1; 
    }
    
    if (y)
    {    
        printLine("x was 0\n");
    }
}

void CWE483_Incorrect_Block_Delimitation__if_without_braces_single_line_01_good()
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
    CWE483_Incorrect_Block_Delimitation__if_without_braces_single_line_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE483_Incorrect_Block_Delimitation__if_without_braces_single_line_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
