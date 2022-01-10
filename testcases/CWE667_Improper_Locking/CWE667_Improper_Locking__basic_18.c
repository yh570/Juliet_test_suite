/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE667_Improper_Locking__basic_18.c
Label Definition File: CWE667_Improper_Locking__basic.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 667 Improper Locking
 * Sinks:
 *    GoodSink: Acquire a lock before releasing it
 *    BadSink : Release the lock before acquiring it
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"


void CWE667_Improper_Locking__basic_18_bad()
{
    goto sink;
sink:
    {
        static stdThreadLock badLock = NULL;
        printLine("Creating lock...");
        if (!stdThreadLockCreate(&badLock))
        {
            printLine("Could not create lock");
            exit(1);
        }
        printLine("Acquiring lock...");
        stdThreadLockAcquire(badLock);
        /* FLAW: Do not release the lock */
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        static stdThreadLock goodLock = NULL;
        printLine("Creating lock...");
        if (!stdThreadLockCreate(&goodLock))
        {
            printLine("Could not create lock");
            exit(1);
        }
        printLine("Acquiring lock...");
        stdThreadLockAcquire(goodLock);
        /* FIX: Release and destroy the lock */
        printLine("Releasing lock...");
        stdThreadLockRelease(goodLock);
        printLine("Destroying lock...");
        stdThreadLockDestroy(goodLock);
    }
}

void CWE667_Improper_Locking__basic_18_good()
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
    CWE667_Improper_Locking__basic_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE667_Improper_Locking__basic_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
