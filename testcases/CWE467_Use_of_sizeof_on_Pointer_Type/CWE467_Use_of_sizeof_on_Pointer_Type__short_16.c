/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__short_16.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * Sinks: short
 *    GoodSink: Use sizeof() the data type
 *    BadSink : Use sizeof() the pointer and not the data type
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE467_Use_of_sizeof_on_Pointer_Type__short_16_bad()
{
    while(1)
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
        break;
    }
}



/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
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
        break;
    }
}

void CWE467_Use_of_sizeof_on_Pointer_Type__short_16_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__short_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__short_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
