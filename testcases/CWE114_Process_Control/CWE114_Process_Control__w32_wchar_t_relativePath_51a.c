/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_relativePath_51a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>


/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_relativePath_51b_badSink(wchar_t * data);

void CWE114_Process_Control__w32_wchar_t_relativePath_51_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FLAW: Specify just the file name for the library, not the full path */
    wcscpy(data, L"winsrv.dll");
    CWE114_Process_Control__w32_wchar_t_relativePath_51b_badSink(data);
}



/* good function declarations */
void CWE114_Process_Control__w32_wchar_t_relativePath_51b_goodG2BSink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    CWE114_Process_Control__w32_wchar_t_relativePath_51b_goodG2BSink(data);
}

void CWE114_Process_Control__w32_wchar_t_relativePath_51_good()
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
    CWE114_Process_Control__w32_wchar_t_relativePath_51_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_relativePath_51_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
