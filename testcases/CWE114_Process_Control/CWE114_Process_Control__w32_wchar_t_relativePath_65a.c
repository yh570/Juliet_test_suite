/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_relativePath_65a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>


/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_relativePath_65b_badSink(wchar_t * data);

void CWE114_Process_Control__w32_wchar_t_relativePath_65_bad()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE114_Process_Control__w32_wchar_t_relativePath_65b_badSink;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FLAW: Specify just the file name for the library, not the full path */
    wcscpy(data, L"winsrv.dll");
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_wchar_t_relativePath_65b_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE114_Process_Control__w32_wchar_t_relativePath_65b_goodG2BSink;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    funcPtr(data);
}

void CWE114_Process_Control__w32_wchar_t_relativePath_65_good()
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
    CWE114_Process_Control__w32_wchar_t_relativePath_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_relativePath_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
