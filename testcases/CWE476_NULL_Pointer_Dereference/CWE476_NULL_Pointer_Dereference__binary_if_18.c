/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__binary_if_18.c
Label Definition File: CWE476_NULL_Pointer_Dereference.pointflaw.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * Sinks: binary_if
 *    GoodSink: Do not check for NULL after the pointer has been dereferenced
 *    BadSink : Check for NULL after a pointer has already been dereferenced
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE476_NULL_Pointer_Dereference__binary_if_18_bad()
{
    goto sink;
sink:
    {
        twoIntsStruct *twoIntsStructPointer = NULL;
        /* FLAW: Using a single & in the if statement will cause both sides of the expression to be evaluated
         * thus causing a NPD */
        if ((twoIntsStructPointer != NULL) & (twoIntsStructPointer->intOne == 5))
        {
            printLine("intOne == 5");
        }
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        twoIntsStruct *twoIntsStructPointer = NULL;
        /* FIX: Use && in the if statement so that if the left side of the expression fails then
         * the right side will not be evaluated */
        if ((twoIntsStructPointer != NULL) && (twoIntsStructPointer->intOne == 5))
        {
            printLine("intOne == 5");
        }
    }
}

void CWE476_NULL_Pointer_Dereference__binary_if_18_good()
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
    CWE476_NULL_Pointer_Dereference__binary_if_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__binary_if_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
