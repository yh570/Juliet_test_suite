/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68a.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_badData;
wchar_t * CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_goodG2BData;


/* bad function declaration */
void CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68b_badSink();

void CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = dataBuffer - 8;
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_badData = data;
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68b_badSink();
}



/* good function declarations */
void CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = dataBuffer;
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_goodG2BData = data;
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68b_goodG2BSink();
}

void CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
