/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: remove
 *    GoodSink: Correctly check if remove() failed
 *    BadSink : Incorrectly check if remove() failed
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define REMOVE _wremove
#else
#define REMOVE remove
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18_bad()
{
    goto sink;
sink:
    /* FLAW: remove() might fail, in which case the return value will be non-zero, but
     * we are checking to see if the return value is 0 */
    if (REMOVE(L"removemebad.txt") == 0)
    {
        printLine("remove failed!");
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    /* FIX: check for the correct return value */
    if (REMOVE(L"removemegood.txt") != 0)
    {
        printLine("remove failed!");
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_remove_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
