/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__char_pointer_malloc_use_01.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: malloc_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from malloc without initialization
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


void CWE758_Undefined_Behavior__char_pointer_malloc_use_01_bad()
{
    {
        char * * pointer = (char * *)malloc(sizeof(char *));
        if (pointer == NULL) {exit(-1);}
        char * data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        free(pointer);
        printLine(data);
    }
}



static void good1()
{
    {
        char * data;
        char * * pointer = (char * *)malloc(sizeof(char *));
        if (pointer == NULL) {exit(-1);}
        data = "string";
        *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
        {
            char * data = *pointer;
            printLine(data);
        }
        free(pointer);
    }
}

void CWE758_Undefined_Behavior__char_pointer_malloc_use_01_good()
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
    CWE758_Undefined_Behavior__char_pointer_malloc_use_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__char_pointer_malloc_use_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
