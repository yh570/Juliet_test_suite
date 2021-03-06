/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_block_10.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_block
 *    GoodSink: Code block contains code
 *    BadSink : An empty code block has no effect
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"


void CWE398_Poor_Code_Quality__empty_block_10_bad()
{
    if(globalTrue)
    {
        /* FLAW: An empty block has no effect */
        {
        }
        printLine("Hello from bad()");
    }
}



/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Do not include an empty block */
        {
            printLine("Inside the block");
        }
        printLine("Hello from good()");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        /* FIX: Do not include an empty block */
        {
            printLine("Inside the block");
        }
        printLine("Hello from good()");
    }
}

void CWE398_Poor_Code_Quality__empty_block_10_good()
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
    CWE398_Poor_Code_Quality__empty_block_10_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_block_10_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
