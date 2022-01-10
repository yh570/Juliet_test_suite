/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__rand_18.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: rand
 *    GoodSink: If specific random number generated, do something harmless
 *    BadSink : If specific random number generated, do something bad
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#define NUM_CHECK 20000


void CWE511_Logic_Time_Bomb__rand_18_bad()
{
    goto sink;
sink:
    /* FLAW: If a certain number, delete a file */
    if (rand() == NUM_CHECK)
    {
        UNLINK("important_file.txt");
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    /* FIX: If a certain number, print to the console */
    if (rand() == NUM_CHECK)
    {
        printLine("Happy New Year!");
    }
}

void CWE511_Logic_Time_Bomb__rand_18_good()
{
    good1();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE511_Logic_Time_Bomb__rand_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__rand_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
