/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__wchar_t_15.c
Label Definition File: CWE469_Use_of_Pointer_Subtraction_to_Determine_Size.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use of Pointer Subtraction to Determine Size
 * Sinks:
 *    GoodSink: Subtract pointers within the same string
 *    BadSink : Subtract pointers to two different strings
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SOURCE_STRING L"abc/opqrstu"


void CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__wchar_t_15_bad()
{
    switch(6)
    {
    case 6:
    {
        wchar_t string1[] = SOURCE_STRING;
        wchar_t string2[] = SOURCE_STRING;
        wchar_t * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = wcschr(string1, L'/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FLAW: subtracting the slash pointer from a completely different string, should be slashInString1 - string1 */
        indexOfSlashInString1 = (size_t)(slashInString1 - string2);
        /* print the index of where the slash was found */
        printUnsignedLine(indexOfSlashInString1);
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
        wchar_t string1[] = SOURCE_STRING;
        wchar_t * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = wcschr(string1, L'/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
        indexOfSlashInString1 = (size_t)(slashInString1 - string1);
        /* print the index of where the slash was found */
        printUnsignedLine(indexOfSlashInString1);
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
        wchar_t string1[] = SOURCE_STRING;
        wchar_t * slashInString1;
        size_t indexOfSlashInString1;
        slashInString1 = wcschr(string1, L'/');
        if (slashInString1 == NULL)
        {
            exit(1);
        }
        /* FIX: subtract the ending pointer from the actual string it originated from (string1) */
        indexOfSlashInString1 = (size_t)(slashInString1 - string1);
        /* print the index of where the slash was found */
        printUnsignedLine(indexOfSlashInString1);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__wchar_t_15_good()
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
    CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__wchar_t_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE469_Use_of_Pointer_Subtraction_to_Determine_Size__wchar_t_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
