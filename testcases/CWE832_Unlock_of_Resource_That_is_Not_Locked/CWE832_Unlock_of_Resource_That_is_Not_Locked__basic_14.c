/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_14.c
Label Definition File: CWE832_Unlock_of_Resource_That_is_Not_Locked__basic.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 832 Unlock Of Resource That Is Not Locked
 * Sinks:
 *    GoodSink: Acquire a lock before releasing it
 *    BadSink : Release the lock before acquiring it
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"


void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_14_bad()
{
    if(globalFive==5)
    {
        {
            static stdThreadLock badLock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&badLock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            /* FLAW: Release the lock before acquiring it */
            printLine("Releasing lock...");
            stdThreadLockRelease(badLock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(badLock);
        }
    }
}



/* good1() uses if(globalFive!=5) instead of if(globalFive==5) */
static void good1()
{
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            static stdThreadLock goodLock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&goodLock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            /* FIX: Acquire the lock before attempting to release it */
            printLine("Acquiring lock...");
            stdThreadLockAcquire(goodLock);
            printLine("Releasing lock...");
            stdThreadLockRelease(goodLock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(goodLock);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalFive==5)
    {
        {
            static stdThreadLock goodLock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&goodLock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            /* FIX: Acquire the lock before attempting to release it */
            printLine("Acquiring lock...");
            stdThreadLockAcquire(goodLock);
            printLine("Releasing lock...");
            stdThreadLockRelease(goodLock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(goodLock);
        }
    }
}

void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_14_good()
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
    CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_14_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_14_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
