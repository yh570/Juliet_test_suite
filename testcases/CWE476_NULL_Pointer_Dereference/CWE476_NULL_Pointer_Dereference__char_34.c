/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_34.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE476_NULL_Pointer_Dereference__char_34_unionType;


void CWE476_NULL_Pointer_Dereference__char_34_bad()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_34_unionType myUnion;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        /* printLine() checks for NULL, so we cannot use it here */
        printHexCharLine(data[0]);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_34_unionType myUnion;
    /* FIX: Initialize data */
    data = "Good";
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        /* printLine() checks for NULL, so we cannot use it here */
        printHexCharLine(data[0]);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    CWE476_NULL_Pointer_Dereference__char_34_unionType myUnion;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        /* FIX: Check for NULL before attempting to print data */
        if (data != NULL)
        {
            /* printLine() checks for NULL, so we cannot use it here */
            printHexCharLine(data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}

void CWE476_NULL_Pointer_Dereference__char_34_good()
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
    CWE476_NULL_Pointer_Dereference__char_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__char_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
