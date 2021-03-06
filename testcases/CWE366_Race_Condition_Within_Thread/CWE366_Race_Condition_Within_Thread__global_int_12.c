/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE366_Race_Condition_Within_Thread__global_int_12.c
Label Definition File: CWE366_Race_Condition_Within_Thread.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 366 Race Condition Within a Thread
 * Sinks: global_int
 *    GoodSink: Acquire a lock before attempting to increment a global integer using another function
 *    BadSink : Do not acquire a lock before attempting to increment a global integer using another function
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

#define N_ITERS 1000000

static int gBadInt = 0;
static int gGoodInt = 0;
static stdThreadLock gGoodLock = NULL;

static void helperBad(void *args)
{
    int i;
    /* FLAW: incrementing an integer is not guaranteed to occur atomically;
     * therefore this operation may not function as intended in multi-threaded
     * programs
     */
    /* I'm going to risk going out on a limb here and making this slightly
     * more complicated to illustrate the point: doing this in a loop a million
     * times makes it much more "obvious" that something wrong might happen
     * (you can even see it in action when you run the program)
     */
    for (i = 0; i < N_ITERS; i++)
    {
        gBadInt = gBadInt + 1;
    }
}

static void helperGood(void *args)
{
    int i;
    /* FIX: acquire a lock before conducting operations that need to occur
     * atomically, and release afterwards */
    stdThreadLockAcquire(gGoodLock);
    for (i = 0; i < N_ITERS; i++)
    {
        gGoodInt = gGoodInt + 1;
    }
    stdThreadLockRelease(gGoodLock);
}


void CWE366_Race_Condition_Within_Thread__global_int_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            stdThread threadA = NULL;
            stdThread threadB = NULL;
            gBadInt = 0;
            if (!stdThreadCreate(helperBad, NULL, &threadA))
            {
                threadA = NULL;
            }
            if (!stdThreadCreate(helperBad, NULL, &threadB))
            {
                threadB = NULL;
            }
            if (threadA && stdThreadJoin(threadA))
            {
                stdThreadDestroy(threadA);
            }
            if (threadB && stdThreadJoin(threadB))
            {
                stdThreadDestroy(threadB);
            }
            printIntLine(gBadInt);
        }
    }
    else
    {
        {
            stdThread threadA = NULL;
            stdThread threadB = NULL;
            if (!stdThreadLockCreate(&gGoodLock))
            {
                return;
            }
            if (!stdThreadCreate(helperGood, NULL, &threadA))
            {
                threadA = NULL;
            }
            if (!stdThreadCreate(helperGood, NULL, &threadB))
            {
                threadB = NULL;
            }
            if (threadA && stdThreadJoin(threadA))
            {
                stdThreadDestroy(threadA);
            }
            if (threadB && stdThreadJoin(threadB))
            {
                stdThreadDestroy(threadB);
            }
            stdThreadLockDestroy(gGoodLock);
            printIntLine(gGoodInt);
        }
    }
}



/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            stdThread threadA = NULL;
            stdThread threadB = NULL;
            if (!stdThreadLockCreate(&gGoodLock))
            {
                return;
            }
            if (!stdThreadCreate(helperGood, NULL, &threadA))
            {
                threadA = NULL;
            }
            if (!stdThreadCreate(helperGood, NULL, &threadB))
            {
                threadB = NULL;
            }
            if (threadA && stdThreadJoin(threadA))
            {
                stdThreadDestroy(threadA);
            }
            if (threadB && stdThreadJoin(threadB))
            {
                stdThreadDestroy(threadB);
            }
            stdThreadLockDestroy(gGoodLock);
            printIntLine(gGoodInt);
        }
    }
    else
    {
        {
            stdThread threadA = NULL;
            stdThread threadB = NULL;
            if (!stdThreadLockCreate(&gGoodLock))
            {
                return;
            }
            if (!stdThreadCreate(helperGood, NULL, &threadA))
            {
                threadA = NULL;
            }
            if (!stdThreadCreate(helperGood, NULL, &threadB))
            {
                threadB = NULL;
            }
            if (threadA && stdThreadJoin(threadA))
            {
                stdThreadDestroy(threadA);
            }
            if (threadB && stdThreadJoin(threadB))
            {
                stdThreadDestroy(threadB);
            }
            stdThreadLockDestroy(gGoodLock);
            printIntLine(gGoodInt);
        }
    }
}

void CWE366_Race_Condition_Within_Thread__global_int_12_good()
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
    CWE366_Race_Condition_Within_Thread__global_int_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE366_Race_Condition_Within_Thread__global_int_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
