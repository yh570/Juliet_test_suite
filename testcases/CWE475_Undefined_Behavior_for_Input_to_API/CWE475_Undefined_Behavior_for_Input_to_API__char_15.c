/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE475_Undefined_Behavior_for_Input_to_API__char_15.c
Label Definition File: CWE475_Undefined_Behavior_for_Input_to_API.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 475 Undefined Behavior for Input to API
 * Sinks:
 *    GoodSink: Copy overlapping memory regions using memmove()
 *    BadSink : Copy overlapping memory regions using memcpy()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE475_Undefined_Behavior_for_Input_to_API__char_15_bad()
{
    switch(6)
    {
    case 6:
    {
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        strcpy(data, "abcdefghijklmnopqrstuvwxyz");
        /* FLAW: Copy overlapping memory regions using memcpy() for which the result is undefined */
        memcpy(data + 6, data + 4, 10*sizeof(char));
        printLine(data);
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
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        strcpy(data, "abcdefghijklmnopqrstuvwxyz");
        /* FIX: Copy overlapping memory regions using memmove() */
        memmove(data + 6, data + 4, 10*sizeof(char));
        printLine(data);
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
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        strcpy(data, "abcdefghijklmnopqrstuvwxyz");
        /* FIX: Copy overlapping memory regions using memmove() */
        memmove(data + 6, data + 4, 10*sizeof(char));
        printLine(data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE475_Undefined_Behavior_for_Input_to_API__char_15_good()
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
    CWE475_Undefined_Behavior_for_Input_to_API__char_15_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE475_Undefined_Behavior_for_Input_to_API__char_15_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
