/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_sscanf_12.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: sscanf
 *    GoodSink: Check if swscanf() fails
 *    BadSink : Do not check if swscanf() fails
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define SRC L"sscanf"


void CWE252_Unchecked_Return_Value__wchar_t_sscanf_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FLAW: Do not check the return value */
            swscanf(SRC, L"%99s\0", data);
        }
    }
    else
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FIX: check the return value */
            if (swscanf(SRC, L"%99s\0", data) == EOF)
            {
                printLine("swscanf failed!");
            }
        }
    }
}



/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FIX: check the return value */
            if (swscanf(SRC, L"%99s\0", data) == EOF)
            {
                printLine("swscanf failed!");
            }
        }
    }
    else
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() and other variants */
            wchar_t dataBuffer[100] = L"";
            wchar_t * data = dataBuffer;
            /* FIX: check the return value */
            if (swscanf(SRC, L"%99s\0", data) == EOF)
            {
                printLine("swscanf failed!");
            }
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_sscanf_12_good()
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
    CWE252_Unchecked_Return_Value__wchar_t_sscanf_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__wchar_t_sscanf_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
