/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__double_12.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE457_Use_of_Uninitialized_Variable__double_12_bad()
{
    double data;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Initialize data */
        data = 5.0;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printDoubleLine(data);
    }
    else
    {
        /* FIX: Ensure data is initialized before use */
        data = 5.0;
        printDoubleLine(data);
    }
}



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    double data;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Ensure data is initialized before use */
        data = 5.0;
        printDoubleLine(data);
    }
    else
    {
        /* FIX: Ensure data is initialized before use */
        data = 5.0;
        printDoubleLine(data);
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    double data;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Initialize data */
        data = 5.0;
    }
    else
    {
        /* FIX: Initialize data */
        data = 5.0;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printDoubleLine(data);
    }
    else
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printDoubleLine(data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__double_12_good()
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
    CWE457_Use_of_Uninitialized_Variable__double_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__double_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
