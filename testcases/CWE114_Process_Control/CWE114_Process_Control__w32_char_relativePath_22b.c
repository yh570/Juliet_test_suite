/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_22b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* The global variable below is used to drive control flow in the source function */
extern int CWE114_Process_Control__w32_char_relativePath_22_badGlobal;

char * CWE114_Process_Control__w32_char_relativePath_22_badSource(char * data)
{
    if(CWE114_Process_Control__w32_char_relativePath_22_badGlobal)
    {
        /* FLAW: Specify just the file name for the library, not the full path */
        strcpy(data, "winsrv.dll");
    }
    return data;
}



/* The global variables below are used to drive control flow in the source functions. */
extern int CWE114_Process_Control__w32_char_relativePath_22_goodG2B1Global;
extern int CWE114_Process_Control__w32_char_relativePath_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
char * CWE114_Process_Control__w32_char_relativePath_22_goodG2B1Source(char * data)
{
    if(CWE114_Process_Control__w32_char_relativePath_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Specify the full pathname for the library */
        strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
char * CWE114_Process_Control__w32_char_relativePath_22_goodG2B2Source(char * data)
{
    if(CWE114_Process_Control__w32_char_relativePath_22_goodG2B2Global)
    {
        /* FIX: Specify the full pathname for the library */
        strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    }
    return data;
}

