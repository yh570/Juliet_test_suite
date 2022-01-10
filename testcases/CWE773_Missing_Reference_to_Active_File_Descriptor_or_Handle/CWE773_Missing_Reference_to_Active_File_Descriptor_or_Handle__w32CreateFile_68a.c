/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using CreateFile()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

HANDLE CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_badDataForBadSink;

HANDLE CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_badDataForGoodSink;


/* bad function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b_badSink();

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_badDataForBadSink = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b_badSink();
}



/* good function declarations */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b_goodB2GSink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_badDataForGoodSink = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68b_goodB2GSink();
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
