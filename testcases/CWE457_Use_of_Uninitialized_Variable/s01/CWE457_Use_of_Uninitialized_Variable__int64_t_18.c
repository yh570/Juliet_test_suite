/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__int64_t_18.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE457_Use_of_Uninitialized_Variable__int64_t_18_bad()
{
    int64_t data;
    goto source;
source:
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
    goto sink;
sink:
    /* POTENTIAL FLAW: Use data without initializing it */
    printLongLongLine(data);
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    int64_t data;
    goto source;
source:
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
    goto sink;
sink:
    /* FIX: Ensure data is initialized before use */
    data = 5LL;
    printLongLongLine(data);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    int64_t data;
    goto source;
source:
    /* FIX: Initialize data */
    data = 5LL;
    goto sink;
sink:
    /* POTENTIAL FLAW: Use data without initializing it */
    printLongLongLine(data);
}

void CWE457_Use_of_Uninitialized_Variable__int64_t_18_good()
{
    goodB2G();
    goodG2B();
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
    CWE457_Use_of_Uninitialized_Variable__int64_t_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__int64_t_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
