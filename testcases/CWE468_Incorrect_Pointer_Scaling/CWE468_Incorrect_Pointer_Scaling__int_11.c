/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE468_Incorrect_Pointer_Scaling__int_11.c
Label Definition File: CWE468_Incorrect_Pointer_Scaling.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 468 Incorrect Pointer Scaling
 * Sinks: int
 *    GoodSink: Do not include sizeof(int) since pointer arithmetic is automatically scaled
 *    BadSink : Included sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"


void CWE468_Incorrect_Pointer_Scaling__int_11_bad()
{
    if(globalReturnsTrue())
    {
        {
            int intArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            int *intPointer = intArray;
            /* get intArray[2] */
            /* FLAW: included *sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled */
            int toPrint = *(intPointer+(2*sizeof(int)));
            printIntLine(toPrint);
        }
    }
}



/* good1() uses if(globalReturnsFalse()) instead of if(globalReturnsTrue()) */
static void good1()
{
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int intArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            int *intPointer = intArray;
            /* get intArray[2] */
            /* FIX: no sizeof() needed since pointer math is automatically scaled */
            int toPrint = *(intPointer+2);
            printIntLine(toPrint);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalReturnsTrue())
    {
        {
            int intArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            int *intPointer = intArray;
            /* get intArray[2] */
            /* FIX: no sizeof() needed since pointer math is automatically scaled */
            int toPrint = *(intPointer+2);
            printIntLine(toPrint);
        }
    }
}

void CWE468_Incorrect_Pointer_Scaling__int_11_good()
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
    CWE468_Incorrect_Pointer_Scaling__int_11_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE468_Incorrect_Pointer_Scaling__int_11_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
