/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* The global variable below is used to drive control flow in the sink function */
extern int CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_badGlobal;

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_badSink(HANDLE data)
{
    if(CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_badGlobal)
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FLAW: Attempt to close the file using close() instead of CloseHandle() */
            _close((int)data);
        }
    }
}



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_goodB2G1Global;
extern int CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_goodB2G2Global;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_goodB2G1Sink(HANDLE data)
{
    if(CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_goodB2G2Sink(HANDLE data)
{
    if(CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_goodB2G2Global)
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FIX: Close the file using CloseHandle() */
            CloseHandle(data);
        }
    }
}

