/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_sscanf_18.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: sscanf
 *    GoodSink: Check if sscanf() fails
 *    BadSink : Do not check if sscanf() fails
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define SRC "sscanf"


void CWE252_Unchecked_Return_Value__char_sscanf_18_bad()
{
    goto sink;
sink:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        /* FLAW: Do not check the return value */
        sscanf(SRC, "%99s\0", data);
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        /* FIX: check the return value */
        if (sscanf(SRC, "%99s\0", data) == EOF)
        {
            printLine("sscanf failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_sscanf_18_good()
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
    CWE252_Unchecked_Return_Value__char_sscanf_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_sscanf_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
