/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_on_Data_Memory_Layout__modify_local_16.c
Label Definition File: CWE188_Reliance_on_Data_Memory_Layout.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: modify_local
 *    GoodSink: Modify the second field of the struct using the field name
 *    BadSink : Attempt to modify second field in struct, assuming the first field is an int
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


void CWE188_Reliance_on_Data_Memory_Layout__modify_local_16_bad()
{
    while(1)
    {
        {
            struct
            {
                char charFirst;
                int intSecond;
            } structCharInt;
            char *charPtr;
            structCharInt.charFirst = 1;
            charPtr = &structCharInt.charFirst;
            /* FLAW: Attempt to modify intSecond assuming intSecond comes after charFirst and
             * is aligned on an int-boundary after charFirst */
            *(int*)(charPtr + sizeof(int)) = 5;
            printIntLine(structCharInt.charFirst);
            printIntLine(structCharInt.intSecond);
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
            struct
            {
                char charFirst;
                int intSecond;
            } structCharInt;
            structCharInt.charFirst = 1;
            /* FIX: Do not make unwarranted assumptions about underlying data model
             * Modify and access data appropriately */
            structCharInt.intSecond = 5;
            printIntLine(structCharInt.charFirst);
            printIntLine(structCharInt.intSecond);
        }
        break;
    }
}

void CWE188_Reliance_on_Data_Memory_Layout__modify_local_16_good()
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
    CWE188_Reliance_on_Data_Memory_Layout__modify_local_16_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE188_Reliance_on_Data_Memory_Layout__modify_local_16_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
