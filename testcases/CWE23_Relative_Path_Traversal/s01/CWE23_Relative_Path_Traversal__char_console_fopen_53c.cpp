/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_console_fopen_53c.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed file name
 * Sink: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
#define FOPEN fopen
#else
#define FOPEN fopen
#endif

namespace CWE23_Relative_Path_Traversal__char_console_fopen_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_d(char * data);

void badSink_c(char * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(char * data);

void goodG2BSink_c(char * data)
{
    goodG2BSink_d(data);
}


} /* close namespace */
