/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82_goodG2B.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82.h"

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82
{

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_82_goodG2B::action(HANDLE data)
{
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

}
