/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_file_w32CreateFile_54c.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Full path and file name
 * Sink: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>

namespace CWE36_Absolute_Path_Traversal__wchar_t_file_w32CreateFile_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_d(wchar_t * data);

void badSink_c(wchar_t * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(wchar_t * data);

void goodG2BSink_c(wchar_t * data)
{
    goodG2BSink_d(data);
}


} /* close namespace */
