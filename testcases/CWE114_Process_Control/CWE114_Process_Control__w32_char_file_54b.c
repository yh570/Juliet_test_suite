/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_file_54b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: file Read input from a file
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE114_Process_Control__w32_char_file_54c_badSink(char * data);

void CWE114_Process_Control__w32_char_file_54b_badSink(char * data)
{
    CWE114_Process_Control__w32_char_file_54c_badSink(data);
}



/* good function declaration */
void CWE114_Process_Control__w32_char_file_54c_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_char_file_54b_goodG2BSink(char * data)
{
    CWE114_Process_Control__w32_char_file_54c_goodG2BSink(data);
}

