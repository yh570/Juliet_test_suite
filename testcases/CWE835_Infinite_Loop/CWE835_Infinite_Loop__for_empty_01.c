/*
 * @description Infinite Loop - for()
 * 
 * */

#include "std_testcase.h"


void CWE835_Infinite_Loop__for_empty_01_bad() 
{
    int i = 0;
    
    /* FLAW: Infinite Loop - for() with no break point */
    for(;;)
    {
        printIntLine(i);
        i++;
    }
}




static void good1() 
{
    int i = 0;

    for(;;)
    {
        /* FIX: Add a break point for the loop if i = 10 */
        if (i == 10) 
        { 
            break; 
        }
        printIntLine(i);
        i++;
    }
}

void CWE835_Infinite_Loop__for_empty_01_good() 
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
    CWE835_Infinite_Loop__for_empty_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE835_Infinite_Loop__for_empty_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
