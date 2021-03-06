/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_54a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>


/* bad function declaration */
void CWE114_Process_Control__w32_char_relativePath_54b_badSink(char * data);

void CWE114_Process_Control__w32_char_relativePath_54_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FLAW: Specify just the file name for the library, not the full path */
    strcpy(data, "winsrv.dll");
    CWE114_Process_Control__w32_char_relativePath_54b_badSink(data);
}



/* good function declaration */
void CWE114_Process_Control__w32_char_relativePath_54b_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    CWE114_Process_Control__w32_char_relativePath_54b_goodG2BSink(data);
}

void CWE114_Process_Control__w32_char_relativePath_54_good()
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
    CWE114_Process_Control__w32_char_relativePath_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_char_relativePath_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
