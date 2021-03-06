/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__TODO_18.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: TODO
 *    GoodSink: Comments show no indications that the code is unfinished
 *    BadSink : Comment contains the word TODO
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE546_Suspicious_Comment__TODO_18_bad()
{
    goto sink;
sink:
    /* FLAW: The following comment has the letters 'TODO' in it*/
    /* TODO: This comment has the letters 'TODO' in it, which is certainly
     * suspicious, because it could indicate this code is not finished.
     */
    printLine("Hello");
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    /* FIX: Removed the suspicious comments */
    printLine("Hello");
}

void CWE546_Suspicious_Comment__TODO_18_good()
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
    CWE546_Suspicious_Comment__TODO_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE546_Suspicious_Comment__TODO_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
