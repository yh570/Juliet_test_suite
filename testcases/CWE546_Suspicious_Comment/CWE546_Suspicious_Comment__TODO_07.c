/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__TODO_07.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: TODO
 *    GoodSink: Comments show no indications that the code is unfinished
 *    BadSink : Comment contains the word TODO
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


void CWE546_Suspicious_Comment__TODO_07_bad()
{
    if(staticFive==5)
    {
        /* FLAW: The following comment has the letters 'TODO' in it*/
        /* TODO: This comment has the letters 'TODO' in it, which is certainly
         * suspicious, because it could indicate this code is not finished.
         */
        printLine("Hello");
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
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

void CWE546_Suspicious_Comment__TODO_07_good()
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
    CWE546_Suspicious_Comment__TODO_07_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE546_Suspicious_Comment__TODO_07_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
