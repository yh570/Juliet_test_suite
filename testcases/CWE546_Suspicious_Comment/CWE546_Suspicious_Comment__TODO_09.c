/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__TODO_09.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: TODO
 *    GoodSink: Comments show no indications that the code is unfinished
 *    BadSink : Comment contains the word TODO
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"


void CWE546_Suspicious_Comment__TODO_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: The following comment has the letters 'TODO' in it*/
        /* TODO: This comment has the letters 'TODO' in it, which is certainly
         * suspicious, because it could indicate this code is not finished.
         */
        printLine("Hello");
    }
}



/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
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
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

void CWE546_Suspicious_Comment__TODO_09_good()
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
    CWE546_Suspicious_Comment__TODO_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE546_Suspicious_Comment__TODO_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
