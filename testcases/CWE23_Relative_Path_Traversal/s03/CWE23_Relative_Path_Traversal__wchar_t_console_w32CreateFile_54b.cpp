/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_console_w32CreateFile_54b.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-54b.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed file name
 * Sink: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

#include <windows.h>

namespace CWE23_Relative_Path_Traversal__wchar_t_console_w32CreateFile_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_c(wchar_t * data);

void badSink_b(wchar_t * data)
{
    badSink_c(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_c(wchar_t * data);

void goodG2BSink_b(wchar_t * data)
{
    goodG2BSink_c(data);
}


} /* close namespace */
