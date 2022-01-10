/*
 * @description Infinite Loop - do..while()
 * 
 * */

#include "std_testcase.h"


void CWE835_Infinite_Loop__do_true_01_bad() 
{
    int i = 0;
    
    /* FLAW: Infinite Loop - do..while(true) with no break point */
    do
    {
        printIntLine(i);
        i++;
    } while(1);
}




static void good1() 
{
    int i = 0;

    do 
    {
        /* FIX: Add a break point for the loop if i = 10 */
        if (i == 10) 
        { 
            break; 
        }
        printIntLine(i);
        i++;
    } while(1);
}

void CWE835_Infinite_Loop__do_true_01_good() 
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
    CWE835_Infinite_Loop__do_true_01_good();
    printLine("Finished good()");

    printLine("Calling bad()...");
    CWE835_Infinite_Loop__do_true_01_bad();
    printLine("Finished bad()");

    return 0;
} 

#endif
