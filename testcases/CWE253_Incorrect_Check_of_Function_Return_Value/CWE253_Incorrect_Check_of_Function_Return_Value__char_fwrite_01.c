/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fwrite
 *    GoodSink: Correctly check if fwrite() failed
 *    BadSink : Incorrectly check if fwrite() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_bad()
{
    /* FLAW: fwrite() might fail, in which case the return value will not be equal to strlen(data),
     * but we are checking to see if the return value is less than 0 */
    if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0)
    {
        printLine("fwrite failed!");
    }
}



static void good1()
{
    /* FIX: check for the correct return value */
    if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
    {
        printLine("fwrite failed!");
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
