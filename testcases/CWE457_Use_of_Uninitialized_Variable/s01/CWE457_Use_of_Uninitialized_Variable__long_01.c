/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__long_01.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE457_Use_of_Uninitialized_Variable__long_01_bad()
{
    long data;
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
    /* POTENTIAL FLAW: Use data without initializing it */
    printLongLine(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    long data;
    /* FIX: Initialize data */
    data = 5L;
    /* POTENTIAL FLAW: Use data without initializing it */
    printLongLine(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    long data;
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
    /* FIX: Ensure data is initialized before use */
    data = 5L;
    printLongLine(data);
}

void CWE457_Use_of_Uninitialized_Variable__long_01_good()
{
    goodG2B();
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
    CWE457_Use_of_Uninitialized_Variable__long_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__long_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
