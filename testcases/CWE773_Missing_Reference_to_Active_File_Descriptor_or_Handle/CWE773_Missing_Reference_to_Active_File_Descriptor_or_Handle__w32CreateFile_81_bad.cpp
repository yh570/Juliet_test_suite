/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81_bad.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using CreateFile()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81.h"

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81
{

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_81_bad::action(HANDLE data) const
{
    /* FLAW: Point data to another file handle without closing the handle from the source */
    data = CreateFile("BadSink_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* avoid incidental for not closing the file handle */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

}
