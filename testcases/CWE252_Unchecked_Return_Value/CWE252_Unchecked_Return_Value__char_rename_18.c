/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_rename_18.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: rename
 *    GoodSink: Check if rename() fails
 *    BadSink : Do not check if rename() fails
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define RENAME rename
#else
#define RENAME rename
#endif

#define OLD_BAD_FILE_NAME "oldbadfilename.txt"
#define OLD_GOOD_FILE_NAME "oldgoodfilename.txt"


void CWE252_Unchecked_Return_Value__char_rename_18_bad()
{
    goto sink;
sink:
    /* FLAW: Do not check the return value */
    RENAME(OLD_BAD_FILE_NAME, "newbadfilename.txt");
}



/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    /* FIX: check the return value */
    if (RENAME(OLD_GOOD_FILE_NAME, "newgoodfilename.txt") != 0)
    {
        printLine("rename failed!");
    }
}

void CWE252_Unchecked_Return_Value__char_rename_18_good()
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
    CWE252_Unchecked_Return_Value__char_rename_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_rename_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
