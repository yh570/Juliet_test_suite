/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_41.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


static void badSink(long * data)
{
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLine(*data);
}

void CWE476_NULL_Pointer_Dereference__long_41_bad()
{
    long * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2BSink(long * data)
{
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLine(*data);
}

static void goodG2B()
{
    long * data;
    long tmpData = 5L;
    /* FIX: Initialize data */
    {
        data = &tmpData;
    }
    goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2GSink(long * data)
{
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        printLongLine(*data);
    }
    else
    {
        printLine("data is NULL");
    }
}

static void goodB2G()
{
    long * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    goodB2GSink(data);
}

void CWE476_NULL_Pointer_Dereference__long_41_good()
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
    CWE476_NULL_Pointer_Dereference__long_41_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__long_41_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
