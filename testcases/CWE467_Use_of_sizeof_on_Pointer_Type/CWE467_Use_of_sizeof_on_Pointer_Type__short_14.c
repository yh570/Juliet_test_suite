/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__short_14.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * Sinks: short
 *    GoodSink: Use sizeof() the data type
 *    BadSink : Use sizeof() the pointer and not the data type
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"


void CWE467_Use_of_sizeof_on_Pointer_Type__short_14_bad()
{
    if(globalFive==5)
    {
        {
            short * badShort = NULL;
            /* FLAW: Using sizeof the pointer and not the data type in malloc() */
            badShort = (short *)malloc(sizeof(badShort));
            if (badShort == NULL) {exit(-1);}
            *badShort = 5;
            printShortLine(*badShort);
            free(badShort);
        }
    }
}



/* good1() uses if(globalFive!=5) instead of if(globalFive==5) */
static void good1()
{
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            short * goodShort = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodShort = (short *)malloc(sizeof(*goodShort));
            if (goodShort == NULL) {exit(-1);}
            *goodShort = 6;
            printShortLine(*goodShort);
            free(goodShort);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalFive==5)
    {
        {
            short * goodShort = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodShort = (short *)malloc(sizeof(*goodShort));
            if (goodShort == NULL) {exit(-1);}
            *goodShort = 6;
            printShortLine(*goodShort);
            free(goodShort);
        }
    }
}

void CWE467_Use_of_sizeof_on_Pointer_Type__short_14_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__short_14_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__short_14_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
