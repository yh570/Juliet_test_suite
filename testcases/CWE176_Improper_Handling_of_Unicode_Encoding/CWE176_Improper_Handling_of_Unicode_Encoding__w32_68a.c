/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE176_Improper_Handling_of_Unicode_Encoding__w32_68a.c
Label Definition File: CWE176_Improper_Handling_of_Unicode_Encoding__w32.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 176 Improper Handling of Unicode Encoding
 * BadSource:  Initialize data as a large unicode string
 * GoodSource: Initialize data as a small unicode string
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#pragma comment( lib, "advapi32" )

wchar_t * CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_badData;
wchar_t * CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_goodG2BData;
wchar_t * CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_goodB2GData;


/* bad function declaration */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_68b_badSink();

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* POTENTIAL FLAW: Initialize data as a large unicode string that will cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644");
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_badData = data;
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68b_badSink();
}



/* good function declarations */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_68b_goodG2BSink();
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Initialize data as a small unicode string that will NOT cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580");
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_goodG2BData = data;
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* POTENTIAL FLAW: Initialize data as a large unicode string that will cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644");
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_goodB2GData = data;
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68b_goodB2GSink();
}

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_good()
{
    goodG2B();
    goodB2G();
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
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
