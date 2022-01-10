/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__wcstombs_01.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: wcstombs
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if wcstombs() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <errno.h>


void CWE391_Unchecked_Error_Condition__wcstombs_01_bad()
{
    {
        size_t bytesTranslated = 0;
        char charString[100];
        charString[0] = '\0';
        bytesTranslated = wcstombs((char *)&charString, L"\xffff", 100);
        /* FLAW: Do not check to see if wcstombs() failed */
        printUnsignedLine(bytesTranslated);
        printLine(charString);
    }
}



static void good1()
{
    {
        size_t bytesTranslated = 0;
        char charString[100];
        charString[0] = '\0';
        errno = 0; /* set errno to zero before calling wcstombs(), which can change its value */
        bytesTranslated = wcstombs((char *)&charString, L"\xffff", 100);
        /* FIX: Check errno to see if wcstombs() failed */
        if (errno == EILSEQ)
        {
            printLine("wcstombs() failed");
            exit(1);
        }
        printUnsignedLine(bytesTranslated);
        printLine(charString);
    }
}

void CWE391_Unchecked_Error_Condition__wcstombs_01_good()
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
    CWE391_Unchecked_Error_Condition__wcstombs_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__wcstombs_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
