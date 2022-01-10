/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01.c
Label Definition File: CWE252_Unchecked_Return_Value__w32ImpersonateSelf.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks:
 *    GoodSink: Check the return value of ImpersonateSelf() and handle it properly
 *    BadSink : Do not check if ImpersonateSelf() fails
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32")


void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01_bad()
{
    /* FLAW: Do not check if ImpersonateSelf() fails */
    ImpersonateSelf(SecurityImpersonation);
}



static void good1()
{
    /* FIX: Check to see if ImpersonateSelf() fails */
    if (!ImpersonateSelf(SecurityImpersonation))
    {
        exit(1);
    }
}

void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01_good()
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
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
