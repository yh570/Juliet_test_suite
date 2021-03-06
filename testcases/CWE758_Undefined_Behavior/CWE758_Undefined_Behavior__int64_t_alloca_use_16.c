/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__int64_t_alloca_use_16.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE758_Undefined_Behavior__int64_t_alloca_use_16_bad()
{
    while(1)
    {
        {
            int64_t * pointer = (int64_t *)ALLOCA(sizeof(int64_t));
            int64_t data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printLongLongLine(data);
        }
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        {
            int64_t data;
            int64_t * pointer = (int64_t *)ALLOCA(sizeof(int64_t));
            data = 5LL;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                int64_t data = *pointer;
                printLongLongLine(data);
            }
        }
        break;
    }
}

void CWE758_Undefined_Behavior__int64_t_alloca_use_16_good()
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
    CWE758_Undefined_Behavior__int64_t_alloca_use_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__int64_t_alloca_use_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
