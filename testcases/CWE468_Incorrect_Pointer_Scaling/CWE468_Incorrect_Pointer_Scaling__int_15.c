/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE468_Incorrect_Pointer_Scaling__int_15.c
Label Definition File: CWE468_Incorrect_Pointer_Scaling.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 468 Incorrect Pointer Scaling
 * Sinks: int
 *    GoodSink: Do not include sizeof(int) since pointer arithmetic is automatically scaled
 *    BadSink : Included sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"


void CWE468_Incorrect_Pointer_Scaling__int_15_bad()
{
    switch(6)
    {
    case 6:
    {
        int intArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int *intPointer = intArray;
        /* get intArray[2] */
        /* FLAW: included *sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled */
        int toPrint = *(intPointer+(2*sizeof(int)));
        printIntLine(toPrint);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}



/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        int intArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int *intPointer = intArray;
        /* get intArray[2] */
        /* FIX: no sizeof() needed since pointer math is automatically scaled */
        int toPrint = *(intPointer+2);
        printIntLine(toPrint);
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        int intArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int *intPointer = intArray;
        /* get intArray[2] */
        /* FIX: no sizeof() needed since pointer math is automatically scaled */
        int toPrint = *(intPointer+2);
        printIntLine(toPrint);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE468_Incorrect_Pointer_Scaling__int_15_good()
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
    CWE468_Incorrect_Pointer_Scaling__int_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE468_Incorrect_Pointer_Scaling__int_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
