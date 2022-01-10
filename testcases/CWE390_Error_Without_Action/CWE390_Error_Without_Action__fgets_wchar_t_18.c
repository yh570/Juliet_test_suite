/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fgets_wchar_t_18.c
Label Definition File: CWE390_Error_Without_Action__fgets.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks:
 *    GoodSink: Check if fgetws() failed and handle errors properly
 *    BadSink : Check to see if fgetws() failed, but do nothing about it
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


void CWE390_Error_Without_Action__fgets_wchar_t_18_bad()
{
    goto sink;
sink:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() */
        wchar_t dataBuffer[100] = L"";
        wchar_t * data = dataBuffer;
        printWLine(L"Please enter a string: ");
        /* FLAW: check the return value, but do nothing if there is an error */
        if (fgetws(data, 100, stdin) == NULL)
        {
            /* do nothing */
        }
        printWLine(data);
    }
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgetws() */
        wchar_t dataBuffer[100] = L"";
        wchar_t * data = dataBuffer;
        printWLine(L"Please enter a string: ");
        /* FIX: check the return value and handle errors properly */
        if (fgetws(data, 100, stdin) == NULL)
        {
            printWLine(L"fgetws failed!");
            exit(1);
        }
        printWLine(data);
    }
}

void CWE390_Error_Without_Action__fgets_wchar_t_18_good()
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
    CWE390_Error_Without_Action__fgets_wchar_t_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__fgets_wchar_t_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
