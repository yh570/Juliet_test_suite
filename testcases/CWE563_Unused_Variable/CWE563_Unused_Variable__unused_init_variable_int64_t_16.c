/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int64_t_16.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE563_Unused_Variable__unused_init_variable_int64_t_16_bad()
{
    int64_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5LL;
    while(1)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}



/* goodB2G() - use badsource and goodsink by changing the conditions on the while statements */
static void goodB2G()
{
    int64_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5LL;
    while(1)
    {
        /* FIX: Use data */
        printLongLongLine(data);
        break;
    }
}

void CWE563_Unused_Variable__unused_init_variable_int64_t_16_good()
{
    goodB2G();
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
    CWE563_Unused_Variable__unused_init_variable_int64_t_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_init_variable_int64_t_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
