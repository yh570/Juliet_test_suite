/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_10.c
Label Definition File: CWE587_Assignment_of_Fixed_Address_to_Pointer__basic.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 587 Assignment of Fixed Address to Pointer
 * Sinks:
 *    GoodSink: Assign the pointer to a stack variable
 *    BadSink : Assign fixed address to pointer
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"


void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_10_bad()
{
    if(globalTrue)
    {
        {
            /* FLAW: Assigning fixed address to pointer */
            char *charPointer = (char*)0x400000;
            printHexCharLine(*charPointer);
        }
    }
}



/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* FIX: Assign the pointer to a stack variable */
            char charStack = 'a';
            char *charPointer = &charStack;
            printHexCharLine(*charPointer);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        {
            /* FIX: Assign the pointer to a stack variable */
            char charStack = 'a';
            char *charPointer = &charStack;
            printHexCharLine(*charPointer);
        }
    }
}

void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_10_good()
{
    good1();
    good2();
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
    CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_10_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_10_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
