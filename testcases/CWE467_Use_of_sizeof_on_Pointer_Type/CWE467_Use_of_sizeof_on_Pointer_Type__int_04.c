/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__int_04.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * Sinks: int
 *    GoodSink: Use sizeof() the data type
 *    BadSink : Use sizeof() the pointer and not the data type
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */


void CWE467_Use_of_sizeof_on_Pointer_Type__int_04_bad()
{
    if(STATIC_CONST_TRUE)
    {
        {
            int * badInt = NULL;
            /* FLAW: Using sizeof the pointer and not the data type in malloc() */
            badInt = (int *)malloc(sizeof(badInt));
            if (badInt == NULL) {exit(-1);}
            *badInt = 5;
            printIntLine(*badInt);
            free(badInt);
        }
    }
}



/* good1() uses if(STATIC_CONST_FALSE) instead of if(STATIC_CONST_TRUE) */
static void good1()
{
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int * goodInt = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodInt = (int *)malloc(sizeof(*goodInt));
            if (goodInt == NULL) {exit(-1);}
            *goodInt = 6;
            printIntLine(*goodInt);
            free(goodInt);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(STATIC_CONST_TRUE)
    {
        {
            int * goodInt = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodInt = (int *)malloc(sizeof(*goodInt));
            if (goodInt == NULL) {exit(-1);}
            *goodInt = 6;
            printIntLine(*goodInt);
            free(goodInt);
        }
    }
}

void CWE467_Use_of_sizeof_on_Pointer_Type__int_04_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__int_04_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__int_04_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
