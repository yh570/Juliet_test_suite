/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE480_Use_of_Incorrect_Operator__basic_18.c
Label Definition File: CWE480_Use_of_Incorrect_Operator__basic.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 480 Use of Incorrect Operator
 * Sinks:
 *    GoodSink: Include parens
 *    BadSink : Forget parens
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

static char* staticStringBad = "Hello";
static char* staticStringGood = "Hello";

static char * helperBad()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return staticStringBad;
    }
}

static char * helperGood()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return staticStringGood;
    }
}


void CWE480_Use_of_Incorrect_Operator__basic_18_bad()
{
    goto sink;
sink:
    /* FLAW: This will never be true becuase the () was omitted.  Also INCIDENTAL CWE 570 Expression Is Always False */
    if(helperBad == NULL)
    {
        printLine("Got a NULL");
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    /* FIX: add () to function call */
    if(helperGood() == NULL) /* this will sometimes be true (depending on the rand() in helperGood) */
    {
        printLine("Got a NULL");
    }
}

void CWE480_Use_of_Incorrect_Operator__basic_18_good()
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
    CWE480_Use_of_Incorrect_Operator__basic_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE480_Use_of_Incorrect_Operator__basic_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
