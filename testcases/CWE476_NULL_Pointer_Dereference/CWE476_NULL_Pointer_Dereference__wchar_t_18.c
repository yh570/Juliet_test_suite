/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_18.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE476_NULL_Pointer_Dereference__wchar_t_18_bad()
{
    wchar_t * data;
    goto source;
source:
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    goto sink;
sink:
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    printWcharLine(data[0]);
}



/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    wchar_t * data;
    goto source;
source:
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    goto sink;
sink:
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        /* printWLine() checks for NULL, so we cannot use it here */
        printWcharLine(data[0]);
    }
    else
    {
        printLine("data is NULL");
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    wchar_t * data;
    goto source;
source:
    /* FIX: Initialize data */
    data = L"Good";
    goto sink;
sink:
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    printWcharLine(data[0]);
}

void CWE476_NULL_Pointer_Dereference__wchar_t_18_good()
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
    CWE476_NULL_Pointer_Dereference__wchar_t_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__wchar_t_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
