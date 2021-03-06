/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__counter_05.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: counter
 *    GoodSink: If counter reaches a certain value, do something harmless
 *    BadSink : If counter reaches a certain value, do something bad
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#define COUNT_CHECK 20000

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */


void CWE511_Logic_Time_Bomb__counter_05_bad()
{
    if(staticTrue)
    {
        {
            int count = 0;
            do
            {
                /* FLAW: If a counter reaches a certain value, delete a file */
                if (count == COUNT_CHECK)
                {
                    UNLINK("important_file.txt");
                }
                count++;
            }
            while(1 == 1);   /* infinite loop */
        }
    }
}



/* good1() uses if(staticFalse) instead of if(staticTrue) */
static void good1()
{
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int count = 0;
            do
            {
                /* FIX: If a counter reaches a certain value, print to the console */
                if (count == COUNT_CHECK)
                {
                    printLine("Happy New Year!");
                }
                count++;
            }
            while(1 == 1);   /* infinite loop */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticTrue)
    {
        {
            int count = 0;
            do
            {
                /* FIX: If a counter reaches a certain value, print to the console */
                if (count == COUNT_CHECK)
                {
                    printLine("Happy New Year!");
                }
                count++;
            }
            while(1 == 1);   /* infinite loop */
        }
    }
}

void CWE511_Logic_Time_Bomb__counter_05_good()
{
    good1();
    good2();
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
    CWE511_Logic_Time_Bomb__counter_05_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__counter_05_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
