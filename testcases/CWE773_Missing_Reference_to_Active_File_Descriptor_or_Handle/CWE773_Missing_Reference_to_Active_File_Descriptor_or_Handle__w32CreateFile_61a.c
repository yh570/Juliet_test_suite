/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using CreateFile()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
HANDLE CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_badSource(HANDLE data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61_bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_badSource(data);
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



/* goodB2G uses the BadSource with the GoodSink */
HANDLE CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_goodB2GSource(HANDLE data);

static void goodB2G()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61b_goodB2GSource(data);
    /* FIX: Close the file from the source before pointing data to a new file handle */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
    data = CreateFile("GoodSink_w32CreateFile.txt",
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

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61_good()
{
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
