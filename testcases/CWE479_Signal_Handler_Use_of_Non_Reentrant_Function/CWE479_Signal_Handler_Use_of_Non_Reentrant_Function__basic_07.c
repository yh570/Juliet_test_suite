/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_07.c
Label Definition File: CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 479 Signal Handler Use of Non-Reentrant Function
 * Sinks:
 *    GoodSink: Don't call a function from within the signal handler
 *    BadSink : malloc() and free() inside a signal handler
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <signal.h>

static void helperBad(int sig)
{
    /* FLAW: malloc and free are not re-entrant */
    /* Used to be printf in here, but we are trying to avoid that.
     * Detecting that printLine ultimately calls printf requires inter-
     * procedural analysis, so we cannot do that either.  So instead,
     * do something very contrived with malloc/free
     */
    void *voidPointer = malloc(10);
    if (voidPointer == NULL) {exit(-1);}
    free(voidPointer);
}

static volatile sig_atomic_t volatileSigAtomic = 0;

static void helperGood(int sig)
{
    /* FIX: Basically, "don't do anything" in signal handlers.  Set a flag at
     * best, and if you have to call a function, ensure it's a re-entrant
     * asynchronous-safe one that doesn't eat up a lot of time
     */
    volatileSigAtomic = sig;
}

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_07_bad()
{
    if(staticFive==5)
    {
        signal(SIGINT, helperBad);
    }
}



/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
static void good1()
{
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        signal(SIGINT, helperGood);
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        signal(SIGINT, helperGood);
    }
}

void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_07_good()
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
    CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_07_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_07_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
