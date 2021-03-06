/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: snprintf
 *    GoodSink: Correctly check if snprintf() failed
 *    BadSink : Incorrectly check if snprintf() failed
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define SRC_STRING "string"

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif


void CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            /* FLAW: snprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) == 0)
            {
                printLine("snprintf failed!");
            }
        }
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            /* FIX: check for the correct return value */
            if (SNPRINTF(data,100-strlen(SRC_STRING)-1, "%s\n", SRC_STRING) < 0)
            {
                printLine("snprintf failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_snprintf_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
