/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fread
 *    GoodSink: Correctly check if fread() failed
 *    BadSink : Incorrectly check if fread() failed
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02_bad()
{
    if(1)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FLAW: fread() might fail, in which case the return value will not be equal to 100-1,
             * but we are checking to see if the return value is equal to 0 */
            if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) == 0)
            {
                printLine("fread failed!");
            }
        }
    }
}



/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FIX: check for the correct return value */
            if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1)
            {
                printLine("fread failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FIX: check for the correct return value */
            if (fread((wchar_t *)data, sizeof(wchar_t), (size_t)(100-1), stdin) != 100-1)
            {
                printLine("fread failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fread_02_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
