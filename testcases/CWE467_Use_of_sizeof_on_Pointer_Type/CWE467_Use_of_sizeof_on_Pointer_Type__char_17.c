/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__char_17.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * Sinks: char
 *    GoodSink: Use sizeof() the data type
 *    BadSink : Use sizeof() the pointer and not the data type
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


void CWE467_Use_of_sizeof_on_Pointer_Type__char_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            char * badChar = NULL;
            /* FLAW: Using sizeof the pointer and not the data type in malloc() */
            badChar = (char *)malloc(sizeof(badChar));
            if (badChar == NULL) {exit(-1);}
            *badChar = 'B';
            printHexCharLine(*badChar);
            free(badChar);
        }
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            char * goodChar = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodChar = (char *)malloc(sizeof(*goodChar));
            if (goodChar == NULL) {exit(-1);}
            *goodChar = 'G';
            printHexCharLine(*goodChar);
            free(goodChar);
        }
    }
}

void CWE467_Use_of_sizeof_on_Pointer_Type__char_17_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__char_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE467_Use_of_sizeof_on_Pointer_Type__char_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
